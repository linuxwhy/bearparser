#pragma once

#include "../ExeNodeWrapper.h"
#include "pe_formats.h"

using namespace pe;

class DataDirEntryWrapper : public ExeNodeWrapper
{
public:
    static pe::IMAGE_DATA_DIRECTORY* getDataDirectory(Executable *exe);

    offset_t getDirEntryAddress();
    pe:: dir_entry getDirEntryType() { return this->entryType; }

protected:
    DataDirEntryWrapper(Executable* pe, pe:: dir_entry v_entryType)
        :  ExeNodeWrapper(pe), entryType(v_entryType)
    {
        wrap();
    }

    pe:: dir_entry entryType;
};

