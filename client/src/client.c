#include "client.h"
//#include <commons/log.h>
//#include <commons/config.h>
//#include <readline/readline.h>

int main(void)
{
	/*---------------------------------------------------PARTE 2-------------------------------------------------------------*/
	int conexion;
	char* ip;
	char* puerto;
	char* valor;

	t_log* logger;
	t_config* config;

	//El log_create esta dentro de iniciarlo
	logger = iniciar_logger(); //Lo creo , si se puede y lo devuelvo sino mensaje de error

	// Usando el logger creado previamente
	// Escribi: "Hola! Soy un log"
	log_info(logger , "Soy un Log");
	//Se desttuye abajo de todo

	//Al config lo creo ahi dentro de la funcion
	config = iniciar_config();
	// Usando el config creado previamente

	char* leer_variables_del_config(t_config* config , char* llave)
	{
		char* variableLeida;

		if((valor = config_get_string_value(config , llave)) ==  NULL)
		{
			printf("ERROR : NO SE PUDO LEER LA VARIABLE DEL CONFIG");
		}
		else
		{
			return variableLeida;
		}

	}

	// Lee las variables de IP, Puerto y Valor
	ip = leer_variables_del_config(config , "IP" );
	puerto = leer_variables_del_config(config , "PUERTO");
	valor = leer_variables_del_config(config , "VALOR");

	//Loggear valor de config
	log_info(logger , valor);


	leer_consola(logger);

	/*---------------------------------------------------PARTE 3-------------------------------------------------------------*/

	// Antes de continuar, tenemos que asegurarnos que el servidor esté corriendo porque lo necesitaremos para lo que sigue.

	// Creamos una conexión hacia el servidor
	conexion = crear_conexion(ip, puerto);

	//enviar CLAVE al servirdor

	paquete(conexion);

	terminar_programa(conexion, logger, config);

	/*---------------------------------------------------PARTE 5-------------------------------------------------------------*/
	// Proximamente
}

t_log* iniciar_logger(void)
{
	t_log* nuevo_logger;

	if((nuevo_logger = log_create("tp0.log" , "client" , true , LOG_LEVEL_INFO )) == NULL)
	 {
		printf("ERROR (PUNTERO NULO) , NO SE PUDO CREAR EL LOG");
	 }
	else
	 {
		return nuevo_logger;
	 }
}

t_config* iniciar_config(void)
{
	t_config* nuevo_config;

	if((nuevo_config = config_create("tp0.config")) == NULL)
	{
		printf("NO SE PUDO CREAR EL CONFIG (PUNTERO NULO)");
	}
	else
	{
		return nuevo_config;
	}
}

void leer_consola(t_log* logger)
{
	char* leido;

	//El primero te lo dejo de yapa
	leido = readline(">");

	//loggeo
	log_info(logger , leido);

	while(strcmp(leido , ) != "")
	{
		if()
		{

		}
		else
		{

		}

	}

	free(leido);

	// Acá la idea es que imprimas por el log lo que recibis de la consola.


}

void paquete(int conexion)
{
	//Ahora toca lo divertido!

	char* leido;
	t_paquete* paquete;
}

void terminar_programa(int conexion, t_log* logger, t_config* config)
{
	//Y por ultimo, para cerrar, hay que liberar lo que utilizamos (conexion, log y config) con las funciones de las commons y del TP mencionadas en el enunciado
	log_destroy(logger);
	config_destroy(config);
}
