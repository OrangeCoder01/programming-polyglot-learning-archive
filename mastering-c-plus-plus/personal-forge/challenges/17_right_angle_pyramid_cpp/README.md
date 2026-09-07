# Right Angle Pyramid
## ${\color{orange}\text{Concept explanation}}$:
Explanation:
```
       This programs prints Asterisk left-sided right-angled pyramid.
```
Input:
```
       (1) The number of rows

       (2) The number of columns
```
output:
```
       (1) Asterisk left-sided right-angled pyramid 
```
Obligation:
```
       The program gives freedom for the user to insert the number of rows and columns
       which was unnecessary and output unexpected printed outputs as when:
              (1) Number of rows excceed columns':
                     Enter number of rows: 8
                     Enter number of columns: 4
                     1|
                     2|
                     3|
                     4|      *
                     5|      ** 
                     6|      *** 
                     7|      **** 
                     8|      ***** 
              
              There are empty lines and the pyramid forms (n x n) where n = (n_rows - n_columns - 1)
              
              (2) Number of rows equal to columns':
                     Enter number of rows: 6
                     Enter number of columns: 6
                     
                            *
                            **
                            ***
                            ****
                            *****
                            ******
                            *******

              Works as expected. 

              (3) Number of rows less than the columns':
                     Enter number of rows: 7
                     Enter number of columns: 15
                                 
                     1|                    *********
                     2|                    **********
                     3|                    ***********
                     4|                    ************
                     5|                    *************
                     6|                    **************
                     7|                    ***************
                     8|                    ****************
                     
              In contrary to obligation (2): 
```

For ${\color{pink}\text{example}}$:
```
Enter number of rows: 15
Enter number of columns: 15
*
**
***
****
*****
******
*******
********
*********
**********
***********
************
*************
**************
***************
****************
```



