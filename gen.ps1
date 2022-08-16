.\tools\win_bison.exe -d -v .\src\mwrap.y -o .\src\mwrap.cc
.\tools\win_flex.exe .\src\mwrap.l

$lex_target_filename = "./src/lex.yy.cc"
if (Test-Path $lex_target_filename)
{
    Remove-Item $lex_target_filename
    mv lex.yy.c $lex_target_filename
}