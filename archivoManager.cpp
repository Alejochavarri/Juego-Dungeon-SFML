#include "archivoManager.h"

Archivo archivoManager::leerRegistro(int pos)
{
    Archivo reg;
    reg.setPuntos(-1);
    FILE* p;
    p = fopen("ArchivoPuntos.dat", "rb");
    if (p == NULL) return reg;
    fseek(p, sizeof(Archivo) * pos, 0);
    fread(&reg, sizeof reg, 1, p);
    fclose(p);
    return reg;
}

int archivoManager::contarRegistros()
{
    FILE* p;
    p = fopen("ArchivoPuntos.dat", "rb");
    if (p == NULL) return -1;
    fseek(p, 0, 2);
    int tam = ftell(p);
    fclose(p);
    return tam / sizeof(Archivo);
}

Archivo archivoManager::registroVacio()
{
    Archivo e;
    e.setNombre("");
    e.setPuntos(0);
    return e;
}
