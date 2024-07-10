//------------------------------------------------------------------------
// Copyright(c) 2024 Dad Design.
// 
// Utility for flashing QSPIFlash memory from a PC
// Memory structure and transmission blocks
//-----------------------------------------------------------------------
#pragma once
#include <stdint.h>
#include <string.h>

namespace Dad {

#define QSPI_SIZE           8388608                         // Size of the QSPI flash memory 8M = 8 * 1024 * 1024
#define QSPI_PAGE_SIZE      4096                            // 4K per page
#define QSPI_PAGE_COUNT     2048                            // Number of QSPI pages for the flasher 2024 * 4096 4MB
#define QSPI_ADRESSE        0x90000000

#define MAX_ENTRY_NAME      40                              // Number of pages reserved at the beginning of QSPI Flash
#define DIR_FILE_COUNT      20                              // Number of entries in the Directory

    // Directory structure
    typedef struct stFile {
        char     Name[MAX_ENTRY_NAME];
        uint32_t Size;
        uint32_t DataAddress;
    } Directory[DIR_FILE_COUNT];

    // Structure of the memory area in QSPI used by the flasher
    typedef uint8_t Page[QSPI_PAGE_SIZE];
    struct stQSPI {
        Page Data[QSPI_PAGE_COUNT];               // Pages used by file data
    };
    static_assert(sizeof(stQSPI) <= QSPI_SIZE, "Memory used > QSPI Flash memory size");


class cQSPI{
	public:
	uint8_t* GetFilePtr(const char *pFileName){
		for(int8_t Index=0; Index < DIR_FILE_COUNT; Index++){
            if(0 == strcmp(Dir[Index].Name, pFileName)){
                return (uint8_t*) Dir[Index].DataAddress;
            }
        }
        return nullptr;
	}
    
    uint32_t GetFileSize(const char* pFileName) {
        for (int8_t Index = 0; Index < DIR_FILE_COUNT; Index++) {
            if (0 == strcmp(Dir[Index].Name, pFileName)) {
                return Dir[Index].Size;
            }
        }
        return 0;
    }

	protected :
	Dad::stFile Dir[DIR_FILE_COUNT];
	uint8_t		Data[QSPI_SIZE - sizeof(Dad::Directory)];
};
} //Dad