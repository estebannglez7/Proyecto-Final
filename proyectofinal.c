
/*      PROYECTO FINAL - CALENDARIO en LENGUAJE C      */

#include <stdio.h>
#include <stdlib.h>  // LIMPIAR PANTALLA
#include <time.h>   //funciones de tiempo

int main()
{
	int dia,mes,anio,semana,moduloMes,febrero,total_mes;    //variables para almacenar el tiempo sobre estructura tm.
	int seleccion = 1;	 // pararespuestas (1-si o 0-no) p buscar otra fecha
	int i,j,k,l,m,cont; //correr ciclos
	i=j=k=m=l=cont=0;  //inicializar variables en 0.
	



    time_t sisTime; 	// TIEMPO REAL
    struct tm *tiempo;	// crear puntero

   
    time(&sisTime);		           // "time" obtiene el tiempo desde nuestro sistema y lo da a sisTime.
    tiempo=localtime(&sisTime);   //Convierte los valores de sisTime a compatibles con la estructura tm y luego asigno ese valor a tiempo.


    dia=tiempo->tm_mday;		      //accedo al valor de dia de la estructura tm y se la asigno a dia
    mes=tiempo->tm_mon;		         //accedo a mes de la estrutura tm y se la asigno a mes
    anio=(tiempo->tm_year)+1900;	//calendario a partir de 1900.

    system ("cls");  //limpia la pantalla

    
	//imprimir 
	printf("\t\t\t  CALENDARIO  \n\n");
	
	printf("Hoy es: %d/%d/%d \n\n\n",dia,mes+1,anio);
	
	




    //regresa al ciclo

    while(seleccion != 0)



{
    // determinar los años bisiestos

    if ((anio%4==0) && (anio%100!=0) || anio%400==0)
    febrero=29;
    else
    febrero=28;

    
	
	
	
	//Agrupacion de mes.
    //Los meses se caracterizan por tener 28,29,30,31 dias...entonces hacemos una agrupacion.

    switch (mes)
    {
		case 3: case 5: case 8: case 10: 
		total_mes=30; 
		break; 
		case 1: 
		total_mes=febrero; 
		break; 
		case 0: case 2: case 4: case 6: case 7: case 9: case 11: 
		total_mes=31; 
		break; 
}

//asignar meses e impresion del mismo en la parte superior

switch (mes)
{
	case 0:printf("\t\tENERO\t%d",anio);break;
	case 1:printf("\t\tFEBRERO\t%d",anio);break;
	case 2:printf("\t\tMARZO\t%d",anio);break;
	case 3:printf("\t\tABRIL\t%d",anio);break;
	case 4:printf("\t\tMAYO\t%d",anio);break;
	case 5:printf("\t\tJUNIO\t%d",anio);break;
	case 6:printf("\t\tJULIO\t%d",anio);break;
	case 7:printf("\t\tAGOSTO\t%d",anio);break;
	case 8:printf("\t\tSEPTIEMBRE\t%d",anio);break;
	case 9:printf("\t\tOCTUBRE\t%d",anio);break;
	case 10:printf("\t\tNOVIEMBRE\t%d",anio);break;
	case 11:printf("\t\tDICIEMBRE\t%d",anio);break;
}

//Modulo Mes
//Esto trata de sacarle el modulo 7 a los limites de cada mes, hasta llegar al mes que se cuenta.

if (febrero==29) //calcula año bbisisesto
{
	switch (mes)
	{
		case 0:moduloMes=0;break;
		case 1:moduloMes=3;break;
		case 2:moduloMes=4;break;
		case 3:moduloMes=0;break;
		case 4:moduloMes=2;break;
		case 5:moduloMes=5;break;
		case 6:moduloMes=0;break;
		case 7:moduloMes=3;break;
		case 8:moduloMes=6;break;
		case 9:moduloMes=1;break;
		case 10:moduloMes=4;break;
		case 11:moduloMes=6;break;
	}

}else
{
	switch (mes)
	{
		case 0:moduloMes=0;break;
		case 1:moduloMes=3;break;
		case 2:moduloMes=3;break;
		case 3:moduloMes=6;break;
		case 4:moduloMes=1;break;
		case 5:moduloMes=4;break;
		case 6:moduloMes=6;break;
		case 7:moduloMes=2;break;
		case 8:moduloMes=5;break;
		case 9:moduloMes=0;break;
		case 10:moduloMes=3;break;
		case 11:moduloMes=5;break;
	}
}


//Calculo del primer dia de la semana.

semana=((anio-1)%7+ ((anio-1)/4 -(3*((anio-1)/100+1)/4))%7+moduloMes+1%7)%7;




// Impresion de dias
printf("\nDo\tLu\tMar\tMier\tJue\tVier\tSab\n");

	
		for(m=0;m<semana;m++) //dar espacios
		printf("\t");

		for(i=1;i<=total_mes;i++) //imprimir dias correspondientes dell mes.
		{
			if(i==8-semana||i==15-semana||i==22-semana||i==29-semana || i== 36-semana)
				printf("\n%d\t",i);
			else	
				printf("%d\t",i);
		}


// preguntar si desea buscar una fecha
// procede a seleccionar 1 para afirmar y 0 para negar
printf("\n\n\t\t %cBuscamos otra fecha? \n\t  1=SI 0=NO\t > ", 168);
scanf("%d",&seleccion);


// if para solo admitr el 1 y 0
while (seleccion<0 || seleccion>1)
{
	printf("ERROR, Ingrese 1/0\n");
	printf("\n\n\t\t %cBuscamos otra fecha?\n\t  1=SI 0=NO\t > ", 168);
	scanf("%d",&seleccion);
}

if (seleccion == 1)
{
	printf("\nIngrese Mes: ");
	scanf("%d",&mes);

mes-=1;
// Al inicio agregamos +1 al mes, ya que contábamos los meses de 0-11,
// esta vez estamos contando de 1-12, por lo que le restamos uno.
// Asi cuando el ciclo empiece de nuevo sumara 1, dejando el mes en el valor que deseamos.

printf ("Ingrese A%co: ", 164);
scanf("%d",&anio);

system  ("cls");  //limpiar la pantalla y borra el calendario anteror
printf("\t\t\tCALENDARIO \n\n");

}
} //while

} //main
