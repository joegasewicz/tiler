//
// Created by joe on 20/08/23.
//

#ifndef TILER_MAP_H
#define TILER_MAP_H

#include <SDL2/SDL.h>
#include <stdint.h>

#define TOTAL_TILE_SECTIONS 12
#define TOTAL_SECTION_TILES 12
#define X_SRC_TILES_TOTAL 8
#define X_DEST_TILES_TOTAL 26
#define TILE_ROWS 3s
#define TILE_COLS 4

#define SPRITE_SHEET_PATH "assets /sprite_sheet0.1.png"

extern const unsigned short int spriteWidth;
extern const unsigned short int spriteHeight;

extern int test_tiles_0[12];
extern int test_tiles_1[12];
extern int test_tiles_2[12];
extern int test_tiles_3[12];
extern int test_tiles_4[12];
extern int test_tiles_5[12];
extern int test_tiles_6[12];
extern int test_tiles_7[12];
extern int test_tiles_8[12];
extern int test_tiles_9[12];
extern int test_tiles_10[12];
extern int test_tiles_11[12];

extern int test_world_map[12 * 12];

extern int world_map[TOTAL_TILE_SECTIONS * TOTAL_SECTION_TILES];

void draw_world_map(SDL_Rect src[TOTAL_SECTION_TILES], SDL_Rect dest[TOTAL_SECTION_TILES]);

typedef struct _Map {
    int rows_length;
    int map_length;
    int _map_sections_index; // private
    int tile_row[TILE_COLS];
} Map;

typedef struct _Tiler {
    int x;
    int y;
} Tiler;

Map *Map_new(int row_length, int map_length);

void Map_draw_map(Map *m, int map_sections[12][12], int map[12 * 12]);

void add_tile_row_to_map(int *row, int *index, const int tile_row[TILE_COLS], int map[TOTAL_TILE_SECTIONS * TOTAL_SECTION_TILES]);

void Map_add_rows(Map *m, int map_sections[12][12], int tile_row[TILE_COLS], int *row, int *index, int map[12 * 12]);

void Map_add_sections(Map *m, int map_sections[12][12], int tile_row[TILE_COLS], int *row, int *index, int map[12 * 12]);

void Map_clean(Map *m);

#endif //TILER_MAP_H
