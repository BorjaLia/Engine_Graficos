echo -Running inital Game configuration-

set "projPath=%~1"
set "outDir=%~2"
set "enginePath=%~3"

echo using projPath: "%projPath%"
echo outDir: "%outDir%"
echo enginePath: "%enginePath%"

cd /d "%projPath%"

echo Copying engine DLLs...
xcopy "%enginePath%*.dll" "%outDir%" /D /Y

echo Copying resource folder...
xcopy "res" "%outDir%res" /E /I /D /Y

echo -Game configuration done-