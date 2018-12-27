#ifdef CHANGED
#include "pageprovider.h"
#include "machine.h"
#include "system.h"





PageProvider::PageProvider() {
    bitmap = new BitMap(NumPhysPages);
}

PageProvider::~PageProvider() {
    delete bitmap;
}

int PageProvider::GetEmptyPage() {
    int empty_page = bitmap->Find();
    memset(&machine->mainMemory[PageSize*empty_page], 0, sizeof(PageSize));
    return empty_page;
}

void PageProvider::ReleasePage(int page) {
    bitmap->Clear(page);
}

int PageProvider::NumAvailPage() {
    return bitmap->NumClear();
}

#endif
