#include <iostream>
#include "elf.h"
#include <string.h>


int main(int argc, char **argv) {
    const char * elfFile = argv[1];
    Elf64_Ehdr header;
    Elf64_Shdr sheader;
    Elf64_Shdr symtab;
    Elf64_Shdr strtab;
    Elf64_Sym sym;
    char sname[32];
    FILE *file = fopen(elfFile, "rb");
    fread(&header, sizeof(header), 1, file);
    fseek(file, header.e_shoff, SEEK_SET);
    fread(&sheader, sizeof(sheader), 1, file);
    for (int i = 0; i < header.e_shnum; i++) {
        fseek(file, header.e_shoff + header.e_shentsize * i, SEEK_SET);
        fread(&sheader, sizeof(sheader), 1, file);
        if (sheader.sh_name == SHT_SYMTAB ) {
            symtab = (Elf64_Shdr) sheader;
        }
        if (sheader.sh_name == SHT_STRTAB) {
            strtab = (Elf64_Shdr) sheader;
        }
    }

    for (int i = 0; i < symtab.sh_size / symtab.sh_entsize; i++) {
        fseek(file, symtab.sh_offset + symtab.sh_entsize * i, SEEK_SET);
        fread(&sym, sizeof(sym), 1, file);
        fseek(file, strtab.sh_offset + sym.st_name, SEEK_SET);
        fread(sname, 1, 32, file);
        fprintf(stdout, "%d\t%ld\t%u\t%u\t%hd\t%s\n", i, sym.st_size, ELF64_ST_TYPE(sym.st_info), ELF64_ST_BIND(sym.st_info), sym.st_shndx, sname);
    }
    return 0;
}