#include <iostream>
#include <windows.h>
#include <iomanip>
#include <aclapi.h>

int main() {
    char FilePath[255] = "myfile.txt";
    DWORD error;
    HANDLE hFile;
    PSID pSidOwner;
    char OwnerName[255] = {0};
    char OwnerRights[4] = {0};
    char DomainName[255] = {0};
    SWORD BufSize = 254;
    PSECURITY_DESCRIPTOR pSD;
    SID_NAME_USE eUse;

    hFile = CreateFile(FilePath, GENERIC_READ, FILE_SHARE_READ, 
                    NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);

    if(hFIle == INVALID_HANDLE_VALUE) {}
    error = GetSecurityInfo(hFile, SE_FILE_OBJECT, OWNER_SECURITY_INFORMATION | DACL_SECURITY_INFORMATION,
                        &pSidOwner, NULL, NULL, NULL, &pSD);

    if(error != ERROR_SUCCESS) {}

    error = LookupAccountSid(NULL, pSidOwner, OwnerName, &BufSize, DomainName, &BufSize, &eUse);
    if(error == 0) {
        error = GetLastError();
        if(error == ERROR_NONE_MAPPED) {}
        else {}
    }

    BOOL HasDACL;
    BOOL DefDACL;
    PACL pDACL;

    error = GetSecurityDescriptorDacl(pSD, &HasDACL, &pDACL, &DefDACL);
    if(error == 0) {}

    if(HasDACL && pDACL) {
        char UserName[255] = {0};
        char DomainName[255] = {0};
        for(int i = 0; i < pDACL->AceCount; ++i) {
            ACE_HEADER *pAce;
            error = GetAce(pDACL, i, (LPVOID*)&pAce);
            if(error == 0) {}
            if(pAce->AceType == ACCESS_ALLOWED_ACE_TYPE) {
                ACCESS_ALLOWED_ACE_TYPE *ace = (ACCESS_ALLOWED_ACE_TYPE*)&pACE;
                DWORD BufSize = 254;
                error = LookupAccountSid(NULL, &ace->SidStart, UserName, &BufSize, DomainName, &BufSize, &eUse);
                if(strcmp(OwnerName, UserName) == 0) {
                    if(ace->Mask&(FILE_READ_DATA | FILE_READ_EA | FILE_READ_ATTRIBUTES))
                        if(OwnerRights[0] != '-') OwnerRights[0] = 'r';
                    if(ace->Mask&(FILE_WRITE_DATA | FILE_APPEND_DATA | FILE_WRITE_EA | FILE_WRITE_ATTRIBUTES))
                        //...
                    
                }
            }
        }
    }





}