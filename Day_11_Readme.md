Elección del problema 11
Este problema se ha elegido puesto que al barajar la posibilidad de hacer el uso de arboles con otros problemas como el del día 16, llegaba un punto en el que se complicaba ya que no era la técnica más adecuada para resolver esos problemas. En cambio este problema se ha adaptado bien al uso de arboles.

Elección de la técnica y alternativa
El uso de árboles para resolver este problema es adecuado porque modela naturalmente el proceso de transformación de las piedras. 
Cada piedra se divide en nuevas piedras dependiendo de su valor y el nivel actual de transformación, creando una estructura jerárquica. 
Los nodos representan piedras, y las ramas representan las transformaciones posibles (división o multiplicación). 
Esta estructura facilita recorrer y contar todas las piedras generadas después de un número fijo de transformaciones (niveles), aprovechando la propiedad recursiva de los árboles para dividir y conquistar el problema. 
El problema del día 11 también se puede resolver utilizando grafos porque las piedras y sus transformaciones se pueden hacer como un conjunto de nodos y conexiones entre esos nodos, lo cual es la estructura fundamental de un grafo. 
En este caso, cada piedra se puede representarse como un nodo, y las reglas de transformación que definen cómo una piedra se convierte en otras pueden considerarse como las aristas que conectan los nodos entre sí. 
El algoritmo podría consistir en explorar este grafo, generando los nodos a medida que se aplica cada una de las transformaciones en los niveles de parpadeo. 

Descripción del código y problemas
El código utiliza una estructura TreeNode para representar cada piedra, con un valor grabado y punteros a sus hijos tanto izquierda como derecha. 
La función build_tree construye el árbol desde una raíz, aplicando las reglas de transformación a cada nivel hasta alcanzar el nivel máximo. 
La función count_stones recorre el árbol y cuenta las piedras en los niveles deseados. Para liberar memoria, la función delete_tree elimina recursivamente los nodos. 
Finalmente, el programa lee un archivo de entrada (input.txt), genera un árbol para cada piedra inicial, calcula el número total de piedras después de las transformaciones, y limpia los recursos usados. 
Durante la realización de este problema han habido varios problemas, el primero de estos era que tras realizar una parte del código no compilaba y daba un error extraño que se pudo solucionar rehaciendo la función de countdigits. 
Otro problema que hubo es que una vez ya compilaba el código la respuesta al problema no era la adecuada, sin embargo al cambiar pequeñas partes del código se pudo solucionar y ahora da la respuesta correcta. 
Por último, aunque la primera parte del problema diese la solución correcta al aumentar la cantidad de parpadeos y al estar todo el rato creando arboles binarios el código no se podía ejecutar porque ocupaba demasiado, es por ello que finalmente se ha tenido que usar tablas hash para reducir el consumo de memoría y así que la segunda parte se pueda hacer. 
Dado que las ramas del árbol pueden repetir los mismos cálculos para ciertos valores de piedras, una tabla hash permite almacenar los resultados previamente calculados. 
Esto evita recalcularlos innecesariamente, reduciendo la complejidad computacional y el uso de memoria. 
La tabla hash (std::unordered_map) utiliza un par (engraving, level) como clave para identificar un estado del árbol, y almacena el número total de piedras calculado para ese estado. 
La función hash (PairHash) permite usar std::pair como clave, asegurando una búsqueda e inserción eficiente en la tabla.

Valoración
A la hora de realizar este problema, se ha aprendido la importancia de las operaciones recursivas, especialmente cuando se trabaja con árboles. 
La implementación de un árbol binario para simular el proceso de transformación de las piedras ha enseñado cómo las decisiones en cuanto a la estructura y el manejo de los datos pueden afectar tanto la eficiencia como la complejidad del programa. 
También se ha visto cómo el uso de excepciones y la validación de entradas son cruciales para evitar errores durante la ejecución, sobre todo cuando se manejan datos de entrada inesperados.


