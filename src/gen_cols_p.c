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
 *   Author       :     Martial BORNET (MB) - September 125 2010
 *
 *   @(#)  [MB] fl_gen_cols_p.c Version 1.1 of 25/09/28 - 
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
     unsigned int         _raws, _cols, _c, _i, _r, _n;
     float                _size, _sz;

     if (argc != 4) {
          fprintf(stderr, "Usage: %s nb_raws nb_columns column_size\n", argv[0]);
          exit(1);
     }

     _raws     = atoi(argv[1]);
     _cols     = atoi(argv[2]);
     _size     = atof(argv[3]);

     if (_cols < 3) {
          fprintf(stderr, "Number of columns must be greater than or equal to 3 ! (submitted = %dà\n", _cols);
          exit(1);
     }

     printf("\\documentclass[a4paper]{article}\n");
     printf("\\usepackage[landscape, margin=1cm]{geometry}\n");
     printf("\\usepackage{array}\n");
     printf("\\usepackage[table]{xcolor}\n");
     printf("\n");

     printf("\\begin{document}\n");

     printf("\\newcommand{\\rb}[1]{\\textcolor{red}{\\textbf{#1}}}\n");
     printf("\\newcommand{\\bb}[1]{\\textcolor{blue}{\\textbf{#1}}}\n");
     printf("\n");

//   printf("\\renewcommand{\\arraystretch}{0.1}\n");
     printf("\n");
     printf("\\definecolor{mygray}{HTML}{D0D0D0}\n");
     printf("\n");

     for (_n = 0; _n < 3; _n++) {
          printf("\\noindent\n");

          /* First line : for macros */
          _sz       = _size * 1.5;
          printf("\\begin{tabular}{");
               printf("|p{%4.2fcm}", _sz);

               /* Array header */
               for (_i = 0, _c = _cols - 1; _i < _c; _i++) {
                    printf("|p{%4.2fcm} p{%4.2fcm}", _size, _size);
               }
               _sz       = _size * 0.5;
               printf("|p{%4.2fcm}|", _sz);
               printf("}\n");

               printf("\\hline\n");

               /* Cells */
               printf("\\cellcolor{mygray} &  ");

               for (_i = 0; _i < _c; _i++) {
                    printf("& &   ");
               }
               printf("\\cellcolor{mygray} ");
               printf("\\\\\n");

               printf("\\hline\n");
          printf("\\end{tabular} \\\\\n");

          /* Remaining of the array : for stack contents */
          printf("\\begin{tabular}{");
               for (_i = 0, _c = _cols; _i < _c; _i++) {
                    printf("|p{%4.2fcm} p{%4.2fcm}", _size, _size);
               }
               printf("|}\n");

               for (_r = 0, _c = _cols - 1; _r < _raws; _r++) {
                    for (_i = 0; _i < _c; _i++) {
                         printf(" & &  ");
                    }
                    printf(" & \\\\\n");
                    printf("\\hline\n");     /* Pour separation des lignes */
               }
          printf("\\end{tabular}\n");
          printf("\n");
          printf("\\vspace{1cm}\n");
     }

     printf("\\end{document}\n");

     return 0;
}
