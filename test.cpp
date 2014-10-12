#include <iostream>
#include <cassert>
using namespace std;

#include "MatfileReader.hpp"

int main(int argc, char *argv[])
{
    MatfileReader* mmr = new MatfileReader("test.mat");
    mmr->parseHeader();
    // cout << mmr->descriptiveText() << endl;
    // cout << mmr->subsysDataOffset() << endl;
    // cout << mmr->version() << endl;
    // cout << mmr->endianIndicator() << endl;
    mmr->gotoData();
    mmr->parseDataElement();
    vector<DataElement*> des = mmr->dataElements();
    // cout << des[0]->dataType() << endl;
    DataElement* de;
    CompressedDataElement* cde;
    if (des[0]->dataType() == miCOMPRESSED) {
        cde = dynamic_cast<CompressedDataElement*>(des[0]);
        assert(cde);
        // fstream fo("compressed.dat", ios_base::out | ios_base::binary);
        // assert(fo);
        // fo.write(cde->decompressedData(), cde->decompressedSize());
        de = cde->reparse();
    }
    ;
    return 0;
}
