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
