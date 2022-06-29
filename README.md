# mg
## Etymology
**mg** : *M* er *g* e

## Description
This is a command line utility specially designed for the Windows Command Line to display text.  
*mg* is kinda similar to `cat` available in linux as it literally just prints out file contents to the `STANDARD OUTPUT HANDLE` aka `stdout`

## Usage
    > mg [flags] [file-names]
For Exmple to show the contents of the file `ILoveU.txt`,  

    C:\>mg ILoveU.txt
    I love you! (snap out of this dream!)
    
    
## Switches
Below is a table of *flags/switches/arguements* you can use with `mg`  

| Flags / Switches / Arguements | Long form | Usage |
|-------------------------------|-----------|-------|
|-h| --help    | Display the help prompt.|
|-v|--version|Show `mg` version.|
|-T|--show-tabs|Show tabs in the file as `^I`|
|-f `<filename>`|--file=`<filename>`|Show the file.<br>Does not consider any flags after it.<br>Example:<br>`mg -f --help` OR `mg --file=--help`,<br>will open a file named `--help` (ofcourse if it exists)|
|-n|--new-line|Adds a newline after displaying each file|
|-l|--new-line-if|Adds a newline after displaying each file, iff the file does not end with a newline|
|-N|--no-new-line|If the file shown ends with a newline, it does not display it|
|-w|--show-win-e|Show windows line endings (`CRLF` or `\r\n`) as `$`|
|-E|--show-ends|Show UNIX line endings(`LF` or `\n`) as `$`|
|-V|--show-nonprinting|Show non printing characters as `^M` except `TABS`. (Works for only `\r`, will improve letaa)|
