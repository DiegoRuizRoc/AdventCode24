Elección del problema
Este problema se ha seleccionado porque nos faltaba programación dinámica y al tener este problema un fichero que se puede recorrer con programación dinámica se ha seleccionado. Había otros problemas como el día 2 o tres que al aplicar programación dinámica daba muchos problemas es por ello que esas opciones se han descartado inmediatamente.



Elección de técnica de programación
Se ha optado por usar programación dinámica para optimizar la búsqueda de la palabra "XMAS" en múltiples direcciones dentro de una cuadrícula.
Al almacenar los resultados en una matriz de memoria (dp), evitamos cálculos redundantes en casos donde la misma subcadena se busca repetidamente desde posiciones y direcciones similares. Esto mejora significativamente la eficiencia a la hora de la resolución de este problema. A este problema se le podría añadir divide y vencerás para acompañar a la programación dinámica y tener un código más eficiente


Explicación del código
El programa está diseñado para contar todas las veces que se repite la palabra "XMAS" en una cuadrícula, considerando las 8 direcciones posibles (horizontal, vertical y diagonales, en ambas orientaciones). Recorre cada celda de la cuadrícula buscando coincidencias con la primera letra de "XMAS". Si se encuentra esta coincidencia, se utiliza la función search_in_direction para explorar si el resto de la palabra se puede formar desde esa posición en una dirección específica. Para optimizar este proceso, el programa emplea una matriz tridimensional dp que almacena los resultados intermedios de cada búsqueda, de modo que no repite cálculos innecesarios en posiciones ya evaluadas previamente.

La función search_in_direction implementa la lógica de búsqueda recursiva en la cuadrícula. Verifica los límites de la cuadrícula, comprueba si la letra actual coincide con la esperada y almacena los resultados en la matriz dp para reutilizarlos si es necesario. Esto se ha realizado para reducir significativamente el tiempo de ejecución en ficheros grandes o con muchas coincidencias superpuestas. Al final, el programa suma todas las veces que se ha repetido la palabra "XMAS" encontradas y muestra el total. 

El principal problema que hemos tenido ha sido que no sumaba bien la cantidad de veces que se repetía la palabra y salía un número mucho más grande que el de la respuesta correcta. Este error se ha solucionado realizando cambios y probando diferentes líneas de código dentro de la función de contar palabras.

Valoración
Este ejercicio nos ha ayudado a comprender cómo la programación dinámica puede optimizar problemas relacionados con la búsqueda al evitar cálculos redundantes. Se ha aprendido a implementar estructuras tridimensionales de memoria (dp[x][y][d]), lo que facilita resolver problemas de búsquedas complejas y superposiciones.
