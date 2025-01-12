Día 10: Tablas Hash

Hemos decidido realizar este problema con el método de tablas hash ya que nos permite realizar un registro de los puntos ya visitados en la matriz de números proporcionada como input. 
De esta manera, vamos almacenando dentro de la tabla hash todos los puntos en los que hemos estado y evitamos realizar de nuevo una comprobación en casillas/puntos que ya hemos visitado.

La búsqueda se realiza de manera recursiva en 4 direcciones (arriba, abajo, izquierda, derecha). 
Cada vez que nos movemos a una nueva celda, se verifica si ya hemos visitado esa celda. 
Al utilizar una tabla hash, podemos comprobar si ya hemos estado ahí rápidamente, esto impide que la búsqueda se quede en un bucle infinito.

Este método es más eficiente que uno de programación dinámica ya que nos permite despreocuparnos del espacio de la tabla para almacenar los puntos ya visitados. 
En lugar de usar una matriz de booleanos o una estructura similar para marcar puntos visitados.

En este caso, utilizamos la posición fila y columna como llaves para la tabla hash, de este modo nos aseguramos de que ese punto solo se inserte una vez. 
En la tabla hash insertamos el elemento Point, que es un dato que contiene los enteros correspondientes a fila y columna. 
Si el punto ya está en la tabla, la función de búsqueda devolverá el punto almacenado, lo que indica que ya hemos visitado ese punto.

Cosas aprendidas:
Implementar   #include <unordered_set>
              #include <unordered_map>
