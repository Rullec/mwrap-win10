/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 ".\\src\\mwrap.y"

/*
 * mwrap.y
 *   Parser for mwrap.
 *
 * Copyright (c) 2007  David Bindel
 * See the file COPYING for copying permissions
 */

#include <stdlib.h>
#include <string.h>
#include <string>
#include "mwrap-ast.h"

 
extern int yylex();
extern int yywrap();
extern int yyerror(const char* s);

using std::string;

bool  mw_generate_catch = false;  // Catch C++ exceptions?
bool  mw_use_cpp_complex = false; // Use C++ complex types?
bool  mw_use_c99_complex = false; // Use C99 complex types?
bool  mw_promote_int = false;     // Convert integer types to mwSize?
int   listing_flag = 0;           // Output filenames from @ commands?
int   mbatching_flag = 0;         // Output on @ commands?
int   linenum = 0;                // Lexer line number
FILE* outfp   = 0;                // MATLAB output file
FILE* outcfp  = 0;                // C output file

static int    type_errs = 0;            // Number of typecheck errors
static int    func_id = 0;              // Assign stub numbers
static Func*  funcs   = 0;              // AST - linked list of functions
static Func*  lastfunc = 0;             // Last link in funcs list
static const char*  mexfunc = "mexfunction";  // Name of mex function
static string current_ifname;           // Current input file name


#define MAX_INCLUDE_DEPTH 10
static string include_stack_names[MAX_INCLUDE_DEPTH];
extern int include_stack_ptr;

void set_include_name(const char* s)
{
    include_stack_names[include_stack_ptr] = current_ifname;
    current_ifname = s;
}

void get_include_name()
{
    current_ifname = include_stack_names[include_stack_ptr].c_str();
}


inline void add_func(Func* func)
{
    static std::map<string,Func*> func_lookup;
    if (!funcs) {
        funcs = func;
        lastfunc = func;
        return;
    } 

    Func*& func_ptr = func_lookup[id_string(func)];
    if (func_ptr) {
        func_ptr->same_next = func;
    } else {
        lastfunc->next = func;
        lastfunc = func;
    }
    func_ptr = func;
}


#line 147 ".\\src\\mwrap.cc"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

#include "mwrap.hh"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_NON_C_LINE = 3,                 /* NON_C_LINE  */
  YYSYMBOL_NEW = 4,                        /* NEW  */
  YYSYMBOL_TYPEDEF = 5,                    /* TYPEDEF  */
  YYSYMBOL_CLASS = 6,                      /* CLASS  */
  YYSYMBOL_FORTRAN = 7,                    /* FORTRAN  */
  YYSYMBOL_ID = 8,                         /* ID  */
  YYSYMBOL_NUMBER = 9,                     /* NUMBER  */
  YYSYMBOL_STRING = 10,                    /* STRING  */
  YYSYMBOL_INPUT = 11,                     /* INPUT  */
  YYSYMBOL_OUTPUT = 12,                    /* OUTPUT  */
  YYSYMBOL_INOUT = 13,                     /* INOUT  */
  YYSYMBOL_14_ = 14,                       /* '='  */
  YYSYMBOL_15_ = 15,                       /* ';'  */
  YYSYMBOL_16_ = 16,                       /* ':'  */
  YYSYMBOL_17_ = 17,                       /* ','  */
  YYSYMBOL_18_ = 18,                       /* '('  */
  YYSYMBOL_19_ = 19,                       /* ')'  */
  YYSYMBOL_20_ = 20,                       /* '*'  */
  YYSYMBOL_21_ = 21,                       /* '&'  */
  YYSYMBOL_22_ = 22,                       /* '['  */
  YYSYMBOL_23_ = 23,                       /* ']'  */
  YYSYMBOL_24_ = 24,                       /* '-'  */
  YYSYMBOL_25_ = 25,                       /* '>'  */
  YYSYMBOL_26_ = 26,                       /* '.'  */
  YYSYMBOL_YYACCEPT = 27,                  /* $accept  */
  YYSYMBOL_statements = 28,                /* statements  */
  YYSYMBOL_statement = 29,                 /* statement  */
  YYSYMBOL_tdef = 30,                      /* tdef  */
  YYSYMBOL_classdef = 31,                  /* classdef  */
  YYSYMBOL_inheritslist = 32,              /* inheritslist  */
  YYSYMBOL_inheritsrest = 33,              /* inheritsrest  */
  YYSYMBOL_funcall = 34,                   /* funcall  */
  YYSYMBOL_args = 35,                      /* args  */
  YYSYMBOL_argsrest = 36,                  /* argsrest  */
  YYSYMBOL_basevar = 37,                   /* basevar  */
  YYSYMBOL_var = 38,                       /* var  */
  YYSYMBOL_iospec = 39,                    /* iospec  */
  YYSYMBOL_quals = 40,                     /* quals  */
  YYSYMBOL_aqual = 41,                     /* aqual  */
  YYSYMBOL_arrayspec = 42,                 /* arrayspec  */
  YYSYMBOL_exprs = 43,                     /* exprs  */
  YYSYMBOL_exprrest = 44,                  /* exprrest  */
  YYSYMBOL_expr = 45,                      /* expr  */
  YYSYMBOL_func = 46                       /* func  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))


/* Stored state numbers (used for stacks). */
typedef yytype_int8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif


#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
#endif

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

#if 1

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* 1 */

#if (! defined yyoverflow \
     && (! defined __cplusplus \
         || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  28
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   75

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  27
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  20
/* YYNRULES -- Number of rules.  */
#define YYNRULES  49
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  81

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   268


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    21,     2,
      18,    19,    20,     2,    17,    24,    26,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,    16,    15,
       2,    14,    25,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    22,     2,    23,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13
};

#if YYDEBUG
/* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,   103,   103,   103,   106,   114,   121,   122,   123,   124,
     127,   145,   152,   155,   156,   158,   161,   162,   165,   166,
     168,   169,   170,   172,   173,   174,   176,   177,   179,   180,
     183,   184,   185,   186,   189,   190,   191,   194,   195,   197,
     200,   201,   204,   205,   208,   209,   212,   213,   214,   217
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if 1
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "NON_C_LINE", "NEW",
  "TYPEDEF", "CLASS", "FORTRAN", "ID", "NUMBER", "STRING", "INPUT",
  "OUTPUT", "INOUT", "'='", "';'", "':'", "','", "'('", "')'", "'*'",
  "'&'", "'['", "']'", "'-'", "'>'", "'.'", "$accept", "statements",
  "statement", "tdef", "classdef", "inheritslist", "inheritsrest",
  "funcall", "args", "argsrest", "basevar", "var", "iospec", "quals",
  "aqual", "arrayspec", "exprs", "exprrest", "expr", "func", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-21)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-34)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      21,   -10,   -21,     4,     8,    15,    29,    -7,    38,    21,
     -21,   -21,   -21,    27,    24,   -21,   -21,    35,    28,   -21,
      25,   -21,   -21,    23,    20,    41,   -21,    30,   -21,   -21,
      32,    22,    31,    42,   -21,   -21,   -21,    33,    36,    44,
     -21,   -21,    34,   -21,   -21,   -21,   -21,    40,    37,    47,
     -21,    43,    46,   -21,    23,   -21,    39,    48,    -9,   -21,
      -2,    49,   -21,   -21,    36,    54,   -21,    37,    25,   -21,
     -21,     1,    43,   -21,   -21,   -21,   -21,   -21,   -21,   -21,
     -21
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,     0,     8,     0,     0,     0,     0,    47,     0,     0,
       6,     7,     5,     0,     0,     9,    49,     0,     0,    48,
      20,    34,    35,    41,     0,     0,    36,    37,     1,     2,
       0,    17,     0,     0,    22,    44,    45,     0,    43,     0,
      21,    38,    47,     4,    30,    31,    32,     0,    19,     0,
      10,    14,     0,    39,     0,    40,     0,     0,    33,    16,
       0,     0,    12,    11,    43,     0,    15,    19,    23,    26,
      28,     0,    14,    42,    46,    18,    25,    24,    27,    29,
      13
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
     -21,    55,   -21,   -21,   -21,   -21,    -6,    45,   -21,     0,
     -21,    10,   -21,     9,   -20,   -21,   -21,     6,    17,   -21
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
       0,     8,     9,    10,    11,    52,    62,    12,    47,    59,
      13,    48,    49,    25,    26,    27,    37,    55,    38,    14
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      34,    20,    44,    45,    46,    15,    68,    69,    70,    77,
      78,    79,    16,    21,    22,    23,    17,    24,    21,    22,
      23,    -3,     1,    18,     2,     3,     4,     5,     6,     7,
     -33,    35,    36,    44,    45,    46,     3,    19,    28,     6,
      42,    30,    31,    32,    33,    39,    50,    23,    76,    40,
      51,    41,    56,    54,    58,    60,    53,    72,    24,    57,
      61,    63,    74,    66,    29,    65,    80,    75,    67,    71,
      73,    64,     0,     0,     0,    43
};

static const yytype_int8 yycheck[] =
{
      20,     8,    11,    12,    13,    15,     8,     9,    10,     8,
       9,    10,     8,    20,    21,    22,     8,    24,    20,    21,
      22,     0,     1,     8,     3,     4,     5,     6,     7,     8,
       8,     8,     9,    11,    12,    13,     4,     8,     0,     7,
       8,    14,    18,     8,    16,    25,    15,    22,    68,     8,
       8,    21,     8,    17,    17,     8,    23,     8,    24,    19,
      17,    15,     8,    15,     9,    26,    72,    67,    58,    60,
      64,    54,    -1,    -1,    -1,    30
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     1,     3,     4,     5,     6,     7,     8,    28,    29,
      30,    31,    34,    37,    46,    15,     8,     8,     8,     8,
       8,    20,    21,    22,    24,    40,    41,    42,     0,    28,
      14,    18,     8,    16,    41,     8,     9,    43,    45,    25,
       8,    21,     8,    34,    11,    12,    13,    35,    38,    39,
      15,     8,    32,    23,    17,    44,     8,    19,    17,    36,
       8,    17,    33,    15,    45,    26,    15,    38,     8,     9,
      10,    40,     8,    44,     8,    36,    41,     8,     9,    10,
      33
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    27,    28,    28,    29,    29,    29,    29,    29,    29,
      30,    31,    32,    33,    33,    34,    35,    35,    36,    36,
      37,    37,    37,    38,    38,    38,    38,    38,    38,    38,
      39,    39,    39,    39,    40,    40,    40,    41,    41,    42,
      43,    43,    44,    44,    45,    45,    46,    46,    46,    46
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     2,     0,     3,     1,     1,     1,     1,     2,
       4,     5,     2,     3,     0,     5,     2,     0,     3,     0,
       2,     3,     3,     3,     4,     4,     3,     4,     3,     4,
       1,     1,     1,     0,     1,     1,     1,     1,     2,     3,
       2,     0,     3,     0,     1,     1,     6,     1,     2,     2
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
  do                                                              \
    if (yychar == YYEMPTY)                                        \
      {                                                           \
        yychar = (Token);                                         \
        yylval = (Value);                                         \
        YYPOPSTACK (yylen);                                       \
        yystate = *yyssp;                                         \
        goto yybackup;                                            \
      }                                                           \
    else                                                          \
      {                                                           \
        yyerror (YY_("syntax error: cannot back up")); \
        YYERROR;                                                  \
      }                                                           \
  while (0)

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif


/* Context of a parse error.  */
typedef struct
{
  yy_state_t *yyssp;
  yysymbol_kind_t yytoken;
} yypcontext_t;

/* Put in YYARG at most YYARGN of the expected tokens given the
   current YYCTX, and return the number of tokens stored in YYARG.  If
   YYARG is null, return the number of expected tokens (guaranteed to
   be less than YYNTOKENS).  Return YYENOMEM on memory exhaustion.
   Return 0 if there are more than YYARGN expected tokens, yet fill
   YYARG up to YYARGN. */
static int
yypcontext_expected_tokens (const yypcontext_t *yyctx,
                            yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  int yyn = yypact[+*yyctx->yyssp];
  if (!yypact_value_is_default (yyn))
    {
      /* Start YYX at -YYN if negative to avoid negative indexes in
         YYCHECK.  In other words, skip the first -YYN actions for
         this state because they are default actions.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;
      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yyx;
      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
        if (yycheck[yyx + yyn] == yyx && yyx != YYSYMBOL_YYerror
            && !yytable_value_is_error (yytable[yyx + yyn]))
          {
            if (!yyarg)
              ++yycount;
            else if (yycount == yyargn)
              return 0;
            else
              yyarg[yycount++] = YY_CAST (yysymbol_kind_t, yyx);
          }
    }
  if (yyarg && yycount == 0 && 0 < yyargn)
    yyarg[0] = YYSYMBOL_YYEMPTY;
  return yycount;
}




#ifndef yystrlen
# if defined __GLIBC__ && defined _STRING_H
#  define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
# else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
# endif
#endif

#ifndef yystpcpy
# if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#  define yystpcpy stpcpy
# else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
static char *
yystpcpy (char *yydest, const char *yysrc)
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
# endif
#endif

#ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
      char const *yyp = yystr;
      for (;;)
        switch (*++yyp)
          {
          case '\'':
          case ',':
            goto do_not_strip_quotes;

          case '\\':
            if (*++yyp != '\\')
              goto do_not_strip_quotes;
            else
              goto append;

          append:
          default:
            if (yyres)
              yyres[yyn] = *yyp;
            yyn++;
            break;

          case '"':
            if (yyres)
              yyres[yyn] = '\0';
            return yyn;
          }
    do_not_strip_quotes: ;
    }

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
}
#endif


static int
yy_syntax_error_arguments (const yypcontext_t *yyctx,
                           yysymbol_kind_t yyarg[], int yyargn)
{
  /* Actual size of YYARG. */
  int yycount = 0;
  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yyctx->yytoken != YYSYMBOL_YYEMPTY)
    {
      int yyn;
      if (yyarg)
        yyarg[yycount] = yyctx->yytoken;
      ++yycount;
      yyn = yypcontext_expected_tokens (yyctx,
                                        yyarg ? yyarg + 1 : yyarg, yyargn - 1);
      if (yyn == YYENOMEM)
        return YYENOMEM;
      else
        yycount += yyn;
    }
  return yycount;
}

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return -1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return YYENOMEM if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                const yypcontext_t *yyctx)
{
  enum { YYARGS_MAX = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  yysymbol_kind_t yyarg[YYARGS_MAX];
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

  /* Actual size of YYARG. */
  int yycount = yy_syntax_error_arguments (yyctx, yyarg, YYARGS_MAX);
  if (yycount == YYENOMEM)
    return YYENOMEM;

  switch (yycount)
    {
#define YYCASE_(N, S)                       \
      case N:                               \
        yyformat = S;                       \
        break
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
#undef YYCASE_
    }

  /* Compute error message size.  Don't count the "%s"s, but reserve
     room for the terminator.  */
  yysize = yystrlen (yyformat) - 2 * yycount + 1;
  {
    int yyi;
    for (yyi = 0; yyi < yycount; ++yyi)
      {
        YYPTRDIFF_T yysize1
          = yysize + yytnamerr (YY_NULLPTR, yytname[yyarg[yyi]]);
        if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
          yysize = yysize1;
        else
          return YYENOMEM;
      }
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return -1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yytname[yyarg[yyi++]]);
          yyformat += 2;
        }
      else
        {
          ++yyp;
          ++yyformat;
        }
  }
  return 0;
}


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;




/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yychar = YYEMPTY; /* Cause a token to be read.  */

  goto yysetstate;


/*------------------------------------------------------------.
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */


  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;


/*-----------.
| yybackup.  |
`-----------*/
yybackup:
  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     '$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
  case 4: /* statement: basevar '=' funcall  */
#line 106 ".\\src\\mwrap.y"
                      { 
      (yyvsp[0].func)->ret = (yyvsp[-2].var); 
      (yyvsp[0].func)->id = ++func_id;
      type_errs += typecheck((yyvsp[0].func), linenum);
      if (outfp)
          print_matlab_call(outfp, (yyvsp[0].func), mexfunc); 
      add_func((yyvsp[0].func));
  }
#line 1501 ".\\src\\mwrap.cc"
    break;

  case 5: /* statement: funcall  */
#line 114 ".\\src\\mwrap.y"
            { 
      (yyvsp[0].func)->id = ++func_id;
      type_errs += typecheck((yyvsp[0].func), linenum);
      if (outfp)
          print_matlab_call(outfp, (yyvsp[0].func), mexfunc); 
      add_func((yyvsp[0].func));
  }
#line 1513 ".\\src\\mwrap.cc"
    break;

  case 9: /* statement: error ';'  */
#line 124 ".\\src\\mwrap.y"
              { yyerrok; }
#line 1519 ".\\src\\mwrap.cc"
    break;

  case 10: /* tdef: TYPEDEF ID ID ';'  */
#line 127 ".\\src\\mwrap.y"
                    { 
      if (strcmp((yyvsp[-2].string), "numeric") == 0) {
          add_scalar_type((yyvsp[-1].string));
      } else if (strcmp((yyvsp[-2].string), "dcomplex") == 0) {
          add_zscalar_type((yyvsp[-1].string));
      } else if (strcmp((yyvsp[-2].string), "fcomplex") == 0) {
          add_cscalar_type((yyvsp[-1].string));
      } else if (strcmp((yyvsp[-2].string), "mxArray") == 0) {
          add_mxarray_type((yyvsp[-1].string));
      } else {
          fprintf(stderr, "Unrecognized typespace: %s\n", (yyvsp[-2].string));
          ++type_errs;
      }
      delete[] (yyvsp[-2].string);
      delete[] (yyvsp[-1].string);
  }
#line 1540 ".\\src\\mwrap.cc"
    break;

  case 11: /* classdef: CLASS ID ':' inheritslist ';'  */
#line 145 ".\\src\\mwrap.y"
                                {
      add_inherits((yyvsp[-3].string), (yyvsp[-1].inherits));
      delete[] (yyvsp[-3].string);
      destroy((yyvsp[-1].inherits));
  }
#line 1550 ".\\src\\mwrap.cc"
    break;

  case 12: /* inheritslist: ID inheritsrest  */
#line 152 ".\\src\\mwrap.y"
                  { (yyval.inherits) = new InheritsDecl((yyvsp[-1].string), (yyvsp[0].inherits)); }
#line 1556 ".\\src\\mwrap.cc"
    break;

  case 13: /* inheritsrest: ',' ID inheritsrest  */
#line 155 ".\\src\\mwrap.y"
                      { (yyval.inherits) = new InheritsDecl((yyvsp[-1].string), (yyvsp[0].inherits)); }
#line 1562 ".\\src\\mwrap.cc"
    break;

  case 14: /* inheritsrest: %empty  */
#line 156 ".\\src\\mwrap.y"
    { (yyval.inherits) = NULL; }
#line 1568 ".\\src\\mwrap.cc"
    break;

  case 15: /* funcall: func '(' args ')' ';'  */
#line 158 ".\\src\\mwrap.y"
                               { (yyval.func) = (yyvsp[-4].func); (yyval.func)->args = (yyvsp[-2].var); }
#line 1574 ".\\src\\mwrap.cc"
    break;

  case 16: /* args: var argsrest  */
#line 161 ".\\src\\mwrap.y"
               { (yyval.var) = (yyvsp[-1].var); (yyval.var)->next = (yyvsp[0].var); }
#line 1580 ".\\src\\mwrap.cc"
    break;

  case 17: /* args: %empty  */
#line 162 ".\\src\\mwrap.y"
    { (yyval.var) = NULL; }
#line 1586 ".\\src\\mwrap.cc"
    break;

  case 18: /* argsrest: ',' var argsrest  */
#line 165 ".\\src\\mwrap.y"
                   {(yyval.var) = (yyvsp[-1].var); (yyval.var)->next = (yyvsp[0].var); }
#line 1592 ".\\src\\mwrap.cc"
    break;

  case 19: /* argsrest: %empty  */
#line 166 ".\\src\\mwrap.y"
    { (yyval.var) = NULL; }
#line 1598 ".\\src\\mwrap.cc"
    break;

  case 20: /* basevar: ID ID  */
#line 168 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var('o', promote_int((yyvsp[-1].string)), NULL, (yyvsp[0].string)); }
#line 1604 ".\\src\\mwrap.cc"
    break;

  case 21: /* basevar: ID quals ID  */
#line 169 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var('o', promote_int((yyvsp[-2].string)), (yyvsp[-1].qual),   (yyvsp[0].string)); }
#line 1610 ".\\src\\mwrap.cc"
    break;

  case 22: /* basevar: ID ID aqual  */
#line 170 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var('o', promote_int((yyvsp[-2].string)), (yyvsp[0].qual),   (yyvsp[-1].string)); }
#line 1616 ".\\src\\mwrap.cc"
    break;

  case 23: /* var: iospec ID ID  */
#line 172 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-2].c),  promote_int((yyvsp[-1].string)), NULL, (yyvsp[0].string)); }
#line 1622 ".\\src\\mwrap.cc"
    break;

  case 24: /* var: iospec ID quals ID  */
#line 173 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-3].c),  promote_int((yyvsp[-2].string)), (yyvsp[-1].qual),   (yyvsp[0].string)); }
#line 1628 ".\\src\\mwrap.cc"
    break;

  case 25: /* var: iospec ID ID aqual  */
#line 174 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-3].c),  promote_int((yyvsp[-2].string)), (yyvsp[0].qual),   (yyvsp[-1].string)); }
#line 1634 ".\\src\\mwrap.cc"
    break;

  case 26: /* var: iospec ID NUMBER  */
#line 176 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-2].c),  promote_int((yyvsp[-1].string)), NULL, (yyvsp[0].string)); }
#line 1640 ".\\src\\mwrap.cc"
    break;

  case 27: /* var: iospec ID quals NUMBER  */
#line 177 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-3].c),  promote_int((yyvsp[-2].string)), (yyvsp[-1].qual),   (yyvsp[0].string)); }
#line 1646 ".\\src\\mwrap.cc"
    break;

  case 28: /* var: iospec ID STRING  */
#line 179 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-2].c),  promote_int((yyvsp[-1].string)), NULL, (yyvsp[0].string)); }
#line 1652 ".\\src\\mwrap.cc"
    break;

  case 29: /* var: iospec ID quals STRING  */
#line 180 ".\\src\\mwrap.y"
                             { (yyval.var) = new Var((yyvsp[-3].c),  promote_int((yyvsp[-2].string)), (yyvsp[-1].qual),   (yyvsp[0].string)); }
#line 1658 ".\\src\\mwrap.cc"
    break;

  case 30: /* iospec: INPUT  */
#line 183 ".\\src\\mwrap.y"
           { (yyval.c) = 'i'; }
#line 1664 ".\\src\\mwrap.cc"
    break;

  case 31: /* iospec: OUTPUT  */
#line 184 ".\\src\\mwrap.y"
           { (yyval.c) = 'o'; }
#line 1670 ".\\src\\mwrap.cc"
    break;

  case 32: /* iospec: INOUT  */
#line 185 ".\\src\\mwrap.y"
           { (yyval.c) = 'b'; }
#line 1676 ".\\src\\mwrap.cc"
    break;

  case 33: /* iospec: %empty  */
#line 186 ".\\src\\mwrap.y"
           { (yyval.c) = 'i'; }
#line 1682 ".\\src\\mwrap.cc"
    break;

  case 34: /* quals: '*'  */
#line 189 ".\\src\\mwrap.y"
              { (yyval.qual) = new TypeQual('*', NULL); }
#line 1688 ".\\src\\mwrap.cc"
    break;

  case 35: /* quals: '&'  */
#line 190 ".\\src\\mwrap.y"
              { (yyval.qual) = new TypeQual('&', NULL); }
#line 1694 ".\\src\\mwrap.cc"
    break;

  case 36: /* quals: aqual  */
#line 191 ".\\src\\mwrap.y"
              { (yyval.qual) = (yyvsp[0].qual); }
#line 1700 ".\\src\\mwrap.cc"
    break;

  case 37: /* aqual: arrayspec  */
#line 194 ".\\src\\mwrap.y"
                  { (yyval.qual) = new TypeQual('a', (yyvsp[0].expr)); }
#line 1706 ".\\src\\mwrap.cc"
    break;

  case 38: /* aqual: arrayspec '&'  */
#line 195 ".\\src\\mwrap.y"
                  { (yyval.qual) = new TypeQual('r', (yyvsp[-1].expr)); }
#line 1712 ".\\src\\mwrap.cc"
    break;

  case 39: /* arrayspec: '[' exprs ']'  */
#line 197 ".\\src\\mwrap.y"
                         { (yyval.expr) = (yyvsp[-1].expr); }
#line 1718 ".\\src\\mwrap.cc"
    break;

  case 40: /* exprs: expr exprrest  */
#line 200 ".\\src\\mwrap.y"
                { (yyval.expr) = (yyvsp[-1].expr); (yyval.expr)->next = (yyvsp[0].expr); }
#line 1724 ".\\src\\mwrap.cc"
    break;

  case 41: /* exprs: %empty  */
#line 201 ".\\src\\mwrap.y"
                { (yyval.expr) = NULL; }
#line 1730 ".\\src\\mwrap.cc"
    break;

  case 42: /* exprrest: ',' expr exprrest  */
#line 204 ".\\src\\mwrap.y"
                    { (yyval.expr) = (yyvsp[-1].expr); (yyval.expr)->next = (yyvsp[0].expr); }
#line 1736 ".\\src\\mwrap.cc"
    break;

  case 43: /* exprrest: %empty  */
#line 205 ".\\src\\mwrap.y"
                    { (yyval.expr) = NULL; }
#line 1742 ".\\src\\mwrap.cc"
    break;

  case 44: /* expr: ID  */
#line 208 ".\\src\\mwrap.y"
           { (yyval.expr) = new Expr((yyvsp[0].string)); }
#line 1748 ".\\src\\mwrap.cc"
    break;

  case 45: /* expr: NUMBER  */
#line 209 ".\\src\\mwrap.y"
           { (yyval.expr) = new Expr((yyvsp[0].string)); }
#line 1754 ".\\src\\mwrap.cc"
    break;

  case 46: /* func: ID '-' '>' ID '.' ID  */
#line 212 ".\\src\\mwrap.y"
                       { (yyval.func) = new Func((yyvsp[-5].string), (yyvsp[-2].string), (yyvsp[0].string), current_ifname, linenum); }
#line 1760 ".\\src\\mwrap.cc"
    break;

  case 47: /* func: ID  */
#line 213 ".\\src\\mwrap.y"
                { (yyval.func) = new Func(NULL, NULL, (yyvsp[0].string), current_ifname, linenum); }
#line 1766 ".\\src\\mwrap.cc"
    break;

  case 48: /* func: FORTRAN ID  */
#line 214 ".\\src\\mwrap.y"
                { (yyval.func) = new Func(NULL, NULL, (yyvsp[0].string), current_ifname, linenum); 
                  (yyval.func)->fort = true;
                }
#line 1774 ".\\src\\mwrap.cc"
    break;

  case 49: /* func: NEW ID  */
#line 217 ".\\src\\mwrap.y"
            { (yyval.func) = new Func(NULL, (yyvsp[0].string), mwrap_strdup("new"), 
                          current_ifname, linenum); 
            }
#line 1782 ".\\src\\mwrap.cc"
    break;


#line 1786 ".\\src\\mwrap.cc"

      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      {
        yypcontext_t yyctx
          = {yyssp, yytoken};
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == -1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = YY_CAST (char *,
                             YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
            if (yymsg)
              {
                yysyntax_error_status
                  = yysyntax_error (&yymsg_alloc, &yymsg, &yyctx);
                yymsgp = yymsg;
              }
            else
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = YYENOMEM;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == YYENOMEM)
          YYNOMEM;
      }
    }

  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
         error, discard it.  */

      if (yychar <= YYEOF)
        {
          /* Return failure if at end of input.  */
          if (yychar == YYEOF)
            YYABORT;
        }
      else
        {
          yydestruct ("Error: discarding",
                      yytoken, &yylval);
          yychar = YYEMPTY;
        }
    }

  /* Else will try to reuse lookahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;
  ++yynerrs;

  /* Do not reclaim the symbols of the rule whose action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
            {
              yyn = yytable[yyn];
              if (0 < yyn)
                break;
            }
        }

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
        YYABORT;


      yydestruct ("Error: popping",
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
  return yyresult;
}

#line 222 ".\\src\\mwrap.y"

#include <stdio.h>
#include <string.h>

extern FILE* yyin;

int yywrap()
{
    return 1;
}

int yyerror(const char* s)
{
    fprintf(stderr, "Parse error (%s:%d): %s\n", current_ifname.c_str(),
            linenum, s); return 0;
}

char* mwrap_strdup(const char* s)
{
    char* result = new char[strlen(s)+1];
    strcpy(result, s);
    return result;
}

const char* help_string = 
"mwrap 0.33.3 - MEX file generator for MATLAB and Octave\n"
"\n"
"Syntax:\n"
"  mwrap [-mex outputmex] [-m output.m] [-c outputmex.c] [-mb]\n"
"        [-list] [-catch] infile1 infile2 ...\n"
"\n"
"  -mex outputmex -- specify the MATLAB mex function name\n"
"  -m output.m    -- generate the MATLAB stub called output.m\n"
"  -c outputmex.c -- generate the C file outputmex.c\n"
"  -mb            -- generate .m files specified with @ redirections\n"
"  -list          -- list files specified with @ redirections\n"
"  -catch         -- generate C++ exception handling code\n"
"  -im            -- convert int, long, uint, and ulong types to mwSize\n"
"  -c99complex    -- add support code for C99 complex types\n"
"  -cppcomplex    -- add support code for C++ complex types\n"
"\n";

int main(int argc, char** argv)
{
    int j;
    int err_flag = 0;
    init_scalar_types();

    if (argc == 1) {
        fprintf(stderr, "%s", help_string);
        return 0;
    } else {
        for (j = 1; j < argc; ++j) {
            if (strcmp(argv[j], "-m") == 0 && j+1 < argc)
                outfp = fopen(argv[j+1], "w+");
            if (strcmp(argv[j], "-c") == 0 && j+1 < argc)
                outcfp = fopen(argv[j+1], "w+");
            if (strcmp(argv[j], "-mex") == 0 && j+1 < argc)
                mexfunc = argv[j+1];
            if (strcmp(argv[j], "-mb") == 0)
                mbatching_flag = 1;
            if (strcmp(argv[j], "-list") == 0)
                listing_flag = 1;
            if (strcmp(argv[j], "-catch") == 0)
                mw_generate_catch = true;
            if (strcmp(argv[j], "-im") == 0)
                mw_promote_int = true;
            if (strcmp(argv[j], "-c99complex") == 0) 
                mw_use_c99_complex = true;
            if (strcmp(argv[j], "-cppcomplex") == 0) 
                mw_use_cpp_complex = true;
        }

        if (mw_use_c99_complex || mw_use_cpp_complex) {
            add_zscalar_type("dcomplex");
            add_cscalar_type("fcomplex");
        }

        for (j = 1; j < argc; ++j) {
            if (strcmp(argv[j], "-m") == 0 ||
                strcmp(argv[j], "-c") == 0 ||
                strcmp(argv[j], "-mex") == 0)
                ++j;
            else if (strcmp(argv[j], "-mb") == 0 ||
                     strcmp(argv[j], "-list") == 0 ||
                     strcmp(argv[j], "-catch") == 0 ||
                     strcmp(argv[j], "-im") == 0 ||
                     strcmp(argv[j], "-c99complex") == 0 ||
                     strcmp(argv[j], "-cppcomplex") == 0);
            else {
                linenum = 1;
                type_errs = 0;
                yyin = fopen(argv[j], "r");
                if (yyin) {
                    current_ifname = argv[j];
                    err_flag += yyparse();
                    fclose(yyin);
                } else {
                    fprintf(stderr, "Could not read %s\n", argv[j]);
                }
                if (type_errs)
                    fprintf(stderr, "%s: %d type errors detected\n", 
                            argv[j], type_errs);
                err_flag += type_errs;
            }
        }
    }
    if (!err_flag && outcfp)
        print_mex_file(outcfp, funcs);
    destroy(funcs);
    destroy_inherits();
    if (outfp)
        fclose(outfp);
    if (outcfp)
        fclose(outcfp);
    return err_flag;
}
