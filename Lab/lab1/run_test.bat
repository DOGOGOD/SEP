:: run_test.bat - 测试脚本  从test.txt输入，输出到output.txt，便于测试程序功能
@echo off
set EXE_PATH=cmake-build-debug\lab1.exe
set INPUT_PATH=spec\test.txt
set OUTPUT_PATH=spec\output.txt
set TEMP_STDOUT=spec\temp_stdout.txt
set TEMP_STDERR=spec\temp_stderr.txt

:: 切换到脚本所在目录（lab1 根目录），避免相对路径错误
cd /d "%~dp0"

:: 先检查可执行文件和输入文件是否存在
if not exist "%EXE_PATH%" (
	> "%TEMP_STDOUT%" echo.
	> "%TEMP_STDERR%" echo Executable not found: %EXE_PATH%
	> "%OUTPUT_PATH%" echo StdErr:
	powershell -Command "[console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding; (Get-Content '%TEMP_STDERR%') | ForEach-Object { $_.Replace('!', '') } | Add-Content '%OUTPUT_PATH%' -Encoding UTF8"
	>> "%OUTPUT_PATH%" echo StdOut:
	del "%TEMP_STDOUT%" >nul 2>&1
	del "%TEMP_STDERR%" >nul 2>&1
	exit /b 1
)

if not exist "%INPUT_PATH%" (
	> "%TEMP_STDOUT%" echo.
	> "%TEMP_STDERR%" echo Input file not found: %INPUT_PATH%
	> "%OUTPUT_PATH%" echo StdErr:
	powershell -Command "[console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding; (Get-Content '%TEMP_STDERR%') | ForEach-Object { $_.Replace('!', '') } | Add-Content '%OUTPUT_PATH%' -Encoding UTF8"
	>> "%OUTPUT_PATH%" echo StdOut:
	del "%TEMP_STDOUT%" >nul 2>&1
	del "%TEMP_STDERR%" >nul 2>&1
	exit /b 1
)

:: 运行程序，重定向输入和输出
"%EXE_PATH%" < "%INPUT_PATH%" > "%TEMP_STDOUT%" 2> "%TEMP_STDERR%"

:: 确保临时输出文件存在，避免 PowerShell 报错
if not exist "%TEMP_STDOUT%" type nul > "%TEMP_STDOUT%"
if not exist "%TEMP_STDERR%" type nul > "%TEMP_STDERR%"

:: 初始化 empty 的输出文件
> "%OUTPUT_PATH%" echo StdErr:

:: 过滤和纠正格式 (去除 ! 符号) 
powershell -Command "[console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding; (Get-Content '%TEMP_STDERR%') | ForEach-Object { $_.Replace('!', '') } | Add-Content '%OUTPUT_PATH%' -Encoding UTF8"

>> "%OUTPUT_PATH%" echo StdOut:

:: 过滤 stdout，只保留包含 "Highest" 或 "GPA" 的行
powershell -Command "[console]::InputEncoding = [console]::OutputEncoding = New-Object System.Text.UTF8Encoding; (Get-Content '%TEMP_STDOUT%') | Where-Object { $_ -match 'Highest|GPA' } | Add-Content '%OUTPUT_PATH%' -Encoding UTF8"

:: 清理临时文件
del "%TEMP_STDOUT%" 
del "%TEMP_STDERR%" 


