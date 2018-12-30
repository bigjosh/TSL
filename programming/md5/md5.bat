@REM Ouput an MD5 hash of the specified file
@REM https://superuser.com/questions/245775/is-there-a-built-in-checksum-utility-on-windows-7
@certutil -hashfile %1 MD5|findstr /v "hash of file"|findstr /v "CertUtil"