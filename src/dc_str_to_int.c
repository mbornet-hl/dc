/* ============================================================================
 * Copyright (C) 2025, Martial Bornet
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 *
 *
 *   Author       :     Martial BORNET (MB) - August 31, 2025
 *
 *   File         :     fl_dc_str_to_int.c
 *
 *   @(#)  [MB] ›"CV Version 1.2 of 25/09/28 - 
 *
 * Sources from the original za command are available on :
 * https://github.com/mbornet-hl/dc
 *
 * ============================================================================
 */

#include <stdio.h>
#include <stdlib.h>

/******************************************************************************

                         MAIN

******************************************************************************/
int main(int argc, char *argv[])
{
     char           *_p;

     if (argc != 2) {
          fprintf(stderr, "Usage: %s string\n", argv[0]);
          exit(1);
     }

     for (_p = argv[1]; *_p != 0; _p++) {
          if (_p == argv[1]) {
               printf("%d ", *_p);
          }
          else {
               printf("256 * %d + ", *_p);
          }
     }

     printf("256 * 10 + p P\n");

     return 0;
}
