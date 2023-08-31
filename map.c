//
// Created by joe on 20/08/23.
/*
*   Destination Tiles:
*   ==================
*   - The destination tiles should render from 0-520
*
*           [
*                [          [         [
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0 0    0,0,0,0   0,0,0,0
*                ],         ],        [
                 [         [
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0 0    0,0,0,0   0,0,0,0
*                ],         ],        [
                 [         [
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0,0,   0,0,0,0,  0,0,0,0,
*                  0,0,0 0    0,0,0,0   0,0,0,0
*                ],         ],        [
*            [
**/
#include "map.h"

static void Map_set_map_sections_index(Map *m);
static void update_tile_row(const int *row_num,  int tile_row[TILE_COLS], const int tile_section[TOTAL_TILE_SECTIONS]);


const unsigned short int spriteWidth = 24;
const unsigned short int spriteHeight = 24;

int world_map[TOTAL_TILE_SECTIONS * TOTAL_SECTION_TILES] = {};

Map *Map_new(const int row_length, const int map_length)
{
    int tile_row[TILE_COLS] = {};
    Map *m = malloc(sizeof(Map));
    m->rows_length = row_length;
    m->_map_sections_index = 0;
    m->map_length = map_length;
    memcpy(m->tile_row, tile_row, TILE_COLS);
    return m;
}

void Map_draw_map(Map *m, int map_sections[12][12], int map[12 * 12])
{
    int row = 0;
    int index = 0;
    for (int i = 0; i < m->map_length/m->rows_length; i++)
    {
        Map_add_sections(m, map_sections, m->tile_row, &row, &index, map);
    }
}

void Map_add_sections(Map *m, int map_sections[12][12], int tile_row[TILE_COLS], int *row, int *index, int map[12 * 12])
{
    for (int i = 0; i < m->rows_length; i++)
    {
        Map_add_rows(m, map_sections, tile_row, row, index, map);
        ++(*row);
    }
    Map_set_map_sections_index(m);
}

void Map_add_rows(Map *m, int map_sections[12][12], int tile_row[TILE_COLS], int *row, int *index, int map[12 * 12])
{

    for (unsigned int i = m->_map_sections_index; i < m->_map_sections_index + m->rows_length; i++)
    {
        update_tile_row(row, tile_row, map_sections[i]);
        add_tile_row_to_map(row, index, tile_row, map);
    }
}

static void update_tile_row(const int *row_num,  int tile_row[TILE_COLS], const int tile_section[TOTAL_TILE_SECTIONS])
{
    int index = 0;
    int end;
    if (*row_num == 0)
    {
        end = TILE_COLS;
    }
    else
    {
        index = *row_num * TILE_COLS;
        end = index + TILE_COLS;
    }
    for(int i = 0; i < end; i++, index++)
        tile_row[i] = tile_section[index];
}

void add_tile_row_to_map(int *row, int *index, const int tile_row[TILE_COLS], int map[TOTAL_TILE_SECTIONS * TOTAL_SECTION_TILES])
{
    for (int i = 0; i < TILE_COLS; i++, ++(*index))
        map[*index] = tile_row[i];
}


static void Map_set_map_sections_index(Map *m)
{
    m->_map_sections_index += (m->rows_length - 1);
}


void Map_clean(Map *m)
{
    free(m->tile_row);
    free(m);
}


void draw_world_map(SDL_Rect src[TOTAL_SECTION_TILES], SDL_Rect dest[TOTAL_SECTION_TILES])
{
    int bgDestX = 0, bgDestY = 0;
    for (int i = 0; i < TOTAL_SECTION_TILES; i++)
    {
        int bgSrcX = 0, bgSrcY = 0;
        // SOURCE
        for(int j = 0; j < test_tiles_0[i]; j++)
        {
            bgSrcX = (j % X_SRC_TILES_TOTAL) * 24;s
            if (j % X_SRC_TILES_TOTAL == 0)
                bgSrcY++;
        }
        // DESTINATION
        bgDestX = (i % X_DEST_TILES_TOTAL) * 24;

        if (i % X_DEST_TILES_TOTAL == 0)
            bgDestY++;

        SDL_Rect rectSrc = { bgSrcX, (bgSrcY-1)*24, 24, 24 };
        SDL_Rect rectDest = { bgDestX, (bgDestY-1)*24, 24, 24 };
        src[i] = rectSrc;
        dest[i] = rectDest;
    }
}

int test_world_map[12 * 12] = {};

// row #1
int test_tiles_0[12] = {
        0, 0, 0, 0,
        00, 00, 00, 00,
        000, 000, 000, 000
};

int test_tiles_1[12] = {
        1, 1, 1, 1,
        11, 11, 11, 11,
        111, 111, 111, 111
};

int test_tiles_2[12] = {
        2, 2, 2, 2,
        22, 22, 22, 22,
        222, 222, 222, 222
};
int test_tiles_3[12] = {
        3, 3, 3, 3,
        33, 33, 33, 33,
        333, 333, 333, 333
};

// row #2
int test_tiles_4[12] = {
        4, 4, 4, 4,
        44, 44, 44, 44,
        444, 444, 444, 444
};

int test_tiles_5[12] = {
        5, 5, 5, 5,
        55, 55, 55, 55,
        555, 555, 555, 555
};

int test_tiles_6[12] = {
        6, 6, 6, 6,
        66, 66, 66, 66,
        666, 666, 666, 666
};
int test_tiles_7[12] = {
        7, 7, 7, 7,
        77, 77, 77, 77,
        777, 777, 777, 777
};

// row #3
int test_tiles_8[12] = {
        8, 8, 8, 8,
        88, 88, 88, 88,
        888, 888, 888, 888
};

int test_tiles_9[12] = {
        9, 9, 9, 9,
        99, 99, 99, 99,
        999, 999, 999, 999
};

int test_tiles_10[12] = {
        10, 10, 10, 10,
        1010, 1010, 1010, 1010,
        101010, 101010, 101010, 101010
};
int test_tiles_11[12] = {
        11, 11, 11, 11,
        1111, 1111, 1111, 1111,
        111111, 111111, 111111, 111111
};
