param(
    [Parameter(Mandatory = $true)]
    [string]$Source,
    [switch]$StageForDebug
)

$ErrorActionPreference = 'Stop'
$sourceFile = Get-Item -LiteralPath $Source
if ($sourceFile.Extension -ne '.c') {
    throw 'Open a C source file before building.'
}

$sourceDirectory = $sourceFile.Directory.FullName
$sourceNames = @($sourceFile.Name)
$outputName = $sourceFile.BaseName + '.exe'

$compilerArguments = @('-std=c17', '-g', '-Wall', '-Wextra')
$compilerArguments += "-fdebug-prefix-map=$sourceDirectory=C:/codex-source"
$compilerArguments += $sourceNames
$compilerArguments += @('-o', $outputName)

Push-Location -LiteralPath $sourceDirectory
try {
    & 'C:\msys64\ucrt64\bin\gcc.exe' @compilerArguments
    $compilerExitCode = $LASTEXITCODE
}
finally {
    Pop-Location
}
if ($compilerExitCode -ne 0) {
    exit $compilerExitCode
}

if ($StageForDebug) {
    $debugDirectory = Join-Path $env:TEMP 'programming11-debug'
    New-Item -ItemType Directory -Force -Path $debugDirectory | Out-Null
    Copy-Item -LiteralPath (Join-Path $sourceDirectory $outputName) `
        -Destination (Join-Path $debugDirectory 'run.exe') -Force
}

exit 0
