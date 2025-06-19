#!/usr/bin/python3
##
## EPITECH PROJECT, 2024
## mapgen [WSL: Ubuntu]
## File description:
## mapgen.py
##

import sys
import random

class mapper:
    def __init__(self, height:int, width:int, wall_density:int):
        self.height = height
        self.width = width
        self.wall_density = wall_density
    def new_map(self):
        with open(f"assets/maps/map_{self.height}_{self.width}.txt", 'w+') as map:
            map.write(f"{self.height};{self.width}\n")
            for i in range(0, self.height):
                if i == 0 or i == self.height - 1:
                    map.write("1" * self.width)
                    map.write("\n")
                    continue
                for j in range(0, self.width):
                    if j == 0  or j == self.width - 1 or (random.randint(0, self.wall_density) == 1):
                        map.write("1")
                        continue
                    map.write("0")
                map.write("\n")

if __name__ == '__main__':
    if len(sys.argv) != 4 or int(sys.argv[1]) <= 0 or int(sys.argv[2]) <= 0 or int(sys.argv[3]) <= 0:
        print(f"{sys.argv[0]}: bad arguments\nusage {sys.argv[0]} [+map_height] [+map_width] [+map_density]")
        sys.exit(84)
    new_file = mapper(int(sys.argv[1]), int(sys.argv[2]), int(sys.argv[3]))
    new_file.new_map()