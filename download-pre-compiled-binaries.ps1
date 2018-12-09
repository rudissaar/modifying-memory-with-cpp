$destinationDir = 'pre-compiled'

$numberCounterUrl = 'http://legacy.murda.eu/downloads/misc/number-counter.exe'
$numberCounterFile = Split-Path $numberCounterUrl -Leaf
$numberCounterPath = "$destinationDir\$numberCounterFile"

$modifierUrl = 'http://legacy.murda.eu/downloads/misc/modifier.exe'
$modifierFile = Split-Path $modifierUrl -Leaf
$modifierPath = "$destinationDir\$modifierFile"

Set-StrictMode -Version 3

function main
{
    If (-not (test-path $destinationDir)) {
        New-Item -ItemType Directory -Force -Path $destinationDir
    }

    if ($?) {
        download $numberCounterUrl $numberCounterPath
        download $modifierUrl $modifierPath
    }
}

function download ([string]$url, [string]$outputFile)
{
    if (-not (Test-Path $outputFile)) {
        try {
            Invoke-WebRequest $url -OutFile $outputFile
        } catch {
            $_

            if (Test-Path $outputFile) {
                Remove-Item -Force $outputFile
            }
        }
    }
}

. main
