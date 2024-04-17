#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <conio.h>
#include <string.h>

const DIM = 100;
const SDIM = 30;

int cargaMatrizUsuario(int fila, int columna, int M[fila][columna]);
void muestraMatriz(int fila, int columna, int M[fila][columna]);
void muestraArregloString (int d, char nombre[][30], int v);
int cargaArregloChar (int d, char c[][d], int v, int DIM, char label[]);
int buscaposMenorArregloString(int d,char a[][d], int v);
int buscarStringenArreglo(int d, char a[][d],int v,char dato []);

int main()
{
    srand(time(NULL));
    int fila = 3;
    int columna = 3;
    int Matriz [fila][columna];

//    char nombre [DIM][SDIM];
//    int vNombres = 0;

    Matriz = cargaMatrizUsuario(fila, columna, Matriz);
    muestraMatriz(fila, columna, Matriz);


//    vNombres = cargaArregloChar(SDIM, nombre, vNombres, DIM, "Ingrese un nombre:");
//    printf("\n <<< Listado de nombres:>>>\n");
//    muestraArregloString(SDIM, nombre, vNombres);

    return 0;
}
int cargaMatrizUsuario(int fila, int columna, int M[fila][columna])
{
    char opcion = 0;

    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            while (opcion !=27){
                printf("\n Ingrese un dato: \n");
                scanf("%d", &M[i][j]);

                printf("\n ESC para salir o cualquier tecla para continuar\n");
                opcion = getch();
                system("cls");
            }
        }
    }
    return ;
}
void muestraMatriz(int fila, int columna, int M[fila][columna])
{
    for(int i = 0; i < fila; i++){
        for(int j = 0; j < columna; j++){
            if ( j % 10 == 0){
                printf("\n");
            }
            printf("Matriz: %5d |", M[i][j]);
        }
    }
}
void muestraArregloString (int d, char nombre[][30], int v)
{
    for(int i = 0; i < v; i++)
    {
        printf("\n %s \n", nombre[i]);
    }
    printf("\n==================================");
}
int cargaArregloChar (int d, char c[][d], int v, int DIM, char label[])
{
    char opcion = 0;
    char s[d];
    while ( v < DIM && opcion != 27)
    {
        printf("\n %s \n", label);
        fflush(stdin);
        //scanf("%s", c[v]);
        gets(s);
        if (strlen(s)<d)
        {
            strcpy(c[v],s);
            v++;
        }
        else
        {
            printf("\n Se excedio de dimension\n");
            getch();
        }

        printf("\n ESC para salir o cualquier tecla para continuar\n");
        opcion = getch();
        system("cls");
    }
    return v;
}
int buscaposMenorArregloString(int d,char a[][d], int v)
{
    int posmenor=0;
    for(int i= 0; i<0; i++)
    {
        if(strcmp(a [i],a[posmenor])<0)
        {
            posmenor=i;
        }
    }
    return posmenor;
}
int buscarStringenArreglo(int d, char a[][d],int v, char dato [])
{
    int flag=0;
    int i=0;
          while (i<v && flag==0)
    {
        if (strcmp(a[i],dato)==0)
        {
            flag=1;
        }
        else
        {
            i++;
        }

    }
    return flag;
}
