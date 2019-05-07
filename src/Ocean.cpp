#include "Ocean.h"

Ocean::Ocean (int size = 100){

    this->size = size;

    cells = (Cell **)malloc(sizeof(Cell *) * size);

    for (int i = 0; i < size; i++){

        cells[i] = (Cell *)malloc(sizeof(Cell) * size);

        for (int j = 0; j < size; j++){

            cells[i][j] = new Cell ({i, j}, this);

            switch (ObjType(rand() % ObjTypeEnd)){

                case STONE:
                    break;

                case PREDATOR:
                    break;

                case PREY:
                    break;

                case CORAL:
                    break;

                default:
                    break;

            }

        }

    }

}