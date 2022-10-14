#include <stdio.h>

typedef struct md2_header md2_header_t;

struct md2_header
{
  int ident;                  /* magic number: "IDP2" */
  int version;                /* version: must be 8 */

  int skinwidth;              /* texture width */
  int skinheight;             /* texture height */

  int framesize;              /* size in bytes of a frame */

  int num_skins;              /* number of skins */
  int num_vertices;           /* number of vertices per frame */
  int num_st;                 /* number of texture coordinates */
  int num_tris;               /* number of triangles */
  int num_glcmds;             /* number of opengl commands */
  int num_frames;             /* number of frames */

  int offset_skins;           /* offset skin data */
  int offset_st;              /* offset texture coordinate data */
  int offset_tris;            /* offset triangle data */
  int offset_frames;          /* offset frame data */
  int offset_glcmds;          /* offset OpenGL command data */
  int offset_end;             /* offset end of file */
};

int is_md2(FILE *fd) {
    fseek(fd, 0, SEEK_SET);
    md2_header_t min_header;
    fread(&min_header, sizeof(md2_header_t), 1, fd);
    char *ident = "IDP2";
    int *ident_int = (int *)ident;
    if(min_header.ident == *ident_int) {
        return 1;
    }
    return 0;
}

int main() {
    FILE *current_file;
    current_file = fopen("file1", "r");
    if(is_md2(current_file)) {
        printf("MD2 file\n");
    }
}
