echo -Running inital Engine configuration-

set "projPath=%~1"
set "outDir=%~2"

echo using projPath: "%projPath%"
echo and outDir: "%outDir%"

cd /d "%projPath%"

echo Copying library dependencies (GLFW)...
xcopy "lib\glfw-3.5.1.bin.WIN64\lib-static-ucrt\*.dll" "%outDir%" /D /Y

echo -Initial configuration done-