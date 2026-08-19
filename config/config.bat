echo -Running inital configuration-

set path=%~1
set out=%~2

echo using %path%
echo and %out%

cd %path%

echo step 1

if not exist %out%\ (
	echo copying library dependencies at

	echo %path%lib\glfw-3.5.1.bin.WIN64\lib-static-ucrt
	copy "%path%lib\glfw-3.5.1.bin.WIN64\lib-static-ucrt\*.dll" "%out%" /y
)

echo -Inital configuration done-