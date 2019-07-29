#include <stdio.h>
#include <stdlib.h>

typedef struct lista
{
	char *nombre;
	struct lista *siguiente;
}Lista;
///////////////////////////////
typedef struct hash
{
	int colisiones;
	Lista *arreglo;
}Hash;
/////////////////////////////
Hash *iniciar_hash(int tam)//
{
	int i=0;
		Hash *arreglo = (Hash*)malloc(sizeof(Hash)*tam);
    	for(i=0;i<tam;i++){
			arreglo[i].colisiones = 0;
			arreglo[i].arreglo = NULL;
	  	}
	return(arreglo);
}
/////////////////////////////
int funcion_hash(char *palabra)
{
	char c=palabra[0];
	int clave = (c + 3)%100;// como las letras minusculas son numeros consecutivos que empiezan de 97 , asl sumarle 3 y dividirlos en 100 el resto
	//generara claves de 0 a 26
	return clave;
}
/////////////////////////////
void Agregar_nodo(Lista *nodox , int indice,char *nombres)
{  
	
	Lista *aux;
	if(nodox->siguiente !=NULL)
	{
		Agregar_nodo(nodox->siguiente,indice,nombres);
	}
	else
	{
	
		
		aux = (Lista*)malloc(sizeof(Lista));
		aux->nombre = nombres ;
		aux->siguiente = NULL;
		nodox->siguiente=aux;
		
	}
}
/////////////////////////////
Hash *agregar(char *nombres, Hash *hash, int tam)// se le pasa como parametro la palabra, la tabla hash y el tamaño del hash
{
	int indice=0;
	Lista *aux;
	indice=funcion_hash(nombres);
	if(hash[indice].arreglo==NULL)//si en la posicion donde se debe ingresar valor es nulo se puede ingresar directamente la clave
	{
		aux = (Lista*)malloc(sizeof(Lista));
		
		aux->nombre = nombres ;
		aux->siguiente = NULL;
		
		hash[indice].arreglo = aux;
	}
	else
	{
		
		aux=hash[indice].arreglo; 
		Agregar_nodo(hash[indice].arreglo,indice,nombres);
	}
}
////////////////////////////
int buscar_palabra(Hash *hash , char *palabra)
{
	if(hash==NULL)
	{
		printf("1 no existe tabla hash");return -1;//
	}
	else
	{
	
		int	 indice=funcion_hash(palabra);
		printf("nombre: %s ",hash[indice].arreglo->nombre);system("pause");
		while(hash[indice].arreglo!=NULL)//si hay algo en ese indice de hash se buscara palabra de lo contrario no esta
		{
			printf("nombre en arregloooo: %s \n palabra a comparar :%s \n",hash[indice].arreglo->nombre,palabra);
			if(hash[indice].arreglo->nombre==palabra)
			{
				printf("son iguales\n\n\n");
			}
			if(strcmp(hash[indice].arreglo->nombre,palabra)==0)// si ambas palabras son iguales strcmp dara 0 , en ese caso palabra se encontro
			{
				printf("palabra encontrada\n");return 0;
			}
			else
			{
				hash[indice].arreglo=hash[indice].arreglo->siguiente;
			}
		}
		 printf("3 palabra no ecnontrada\n ");return -1;
	}
}
/////////////////////////////////
Hash *crear_tabla_hash(char *nombrearchivo,int tam)
{
	Hash *hash=iniciar_hash(tam);
  FILE *op;
  int letra,contadordelargodepalabras=-1,i=0,cantidaddepalabras=0;
  char *nombre;
  
  op=fopen(nombrearchivo,"r");
  if(op==NULL)
  {
	printf("archivo no existe\n");  	
  }	
  else
  {
  		while((letra=fgetc(op))!=EOF)//mientras no se llegue a final de archivo
  		{
  			if(hash[9].arreglo!=NULL)
			{
				printf("nombreenhashhhhhhhhhhhhhh: %s \n",hash[9].arreglo->nombre);system("pause");
			}
  			
  			
  		//	printf("posicion puntero:%d \n",posicion_puntero);
  				printf("letra %c \n",letra)	;system("pause");
  				contadordelargodepalabras++;
  			if((letra=='\n'))//si se halla salto de linea se terminara de contar largo de palabra y se pedira memoria para almacenar nombre
  			{
  				cantidaddepalabras++;
  				nombre=malloc(sizeof(nombre)*contadordelargodepalabras);
  				fseek(op,-contadordelargodepalabras-1,SEEK_CUR);// se devuelve posicion a la posicion de inicio de nombre
  			
  				fgets(nombre,contadordelargodepalabras+4,op);// se pasa el nombre a array nombre y esto se mandara a hash
  				agregar(nombre,hash,tam);
  					contadordelargodepalabras=0;
			}
			printf("largo de nombre : %d \n",contadordelargodepalabras);
		}
  }
  printf("cantidad de palabras: %d \n",cantidaddepalabras);
  
 	char nombre_[15];
  	printf("ingrese palabra que desea buscar\n");
	scanf("%s",nombre_);
	buscar_palabra(hash,nombre_);
}
//////////////////////////////



