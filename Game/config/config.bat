echo -Running inital Game configuration-

set path=%~1
set out=%~2
set enginePath=%~3

echo using %path%
echo and %out%

cd %path%

echo step 1

echo copying engine library at

echo %out%
copy "%enginePath%*.dll" "%out%" /y