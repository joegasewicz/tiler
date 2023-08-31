# Tiler
Util to create huge 2d sprite maps
```c
int map_sections[9][9] = {};
memcpy(map_sections[0], test_tiles_0, sizeof(int)*9);
memcpy(map_sections[1], test_tiles_1, sizeof(int)*9);
memcpy(map_sections[2], test_tiles_2, sizeof(int)*9);
memcpy(map_sections[3], test_tiles_3, sizeof(int)*9);
memcpy(map_sections[4], test_tiles_4, sizeof(int)*9);
memcpy(map_sections[5], test_tiles_5, sizeof(int)*9);
memcpy(map_sections[6], test_tiles_6, sizeof(int)*9);
memcpy(map_sections[7], test_tiles_7, sizeof(int)*9);
memcpy(map_sections[8], test_tiles_8, sizeof(int)*9);
```

Take each map sections & merge into a single massive map
```c
Map *map = Map_new(3, 9);
Map_draw_map(map, map_sections, test_world_map);
```
```
[
    [          [         [
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0 0    0,0,0,0   0,0,0,0
    ],         ],        [
     [         [
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0 0    0,0,0,0   0,0,0,0
    ],         ],        [
     [         [
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0,0,   0,0,0,0,  0,0,0,0,
      0,0,0 0    0,0,0,0   0,0,0,0
    ],         ],        [
[

// converts to ->
[
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0,
    0,0,0,0,0,0,0,0,0,0,0,0, ... etc
];
```