Día 23

Parte 1: Encontrar tríos interconectados que incluyan nodos que comiencen con 't'

Técnicas y estructuras de datos:

1. Grafo representado mediante un mapa de adyacencia:
   - Se utiliza un unordered_map<string, unordered_set<string>>.
   - Claves representan nodos, valores los nodos conectados.
2. Fuerza bruta para verificar tríos:
   - Tres bucles anidados enumeran todos los posibles conjuntos de tres nodos.
   - Se verifica si forman un triángulo comprobando conexiones entre pares de nodos.
3. Filtro por condición:
   - Solo se consideran tríos donde al menos un nodo comienza con 't'.

Resolución:
1. Leer el grafo desde un archivo y construir el mapa de adyacencia.
2. Enumerar tríos de nodos mediante tres bucles.
3. Verificar si cada trío forma un triángulo.
4. Filtrar tríos que cumplen la condición del nodo inicial 't'.
5. Contar y mostrar los tríos encontrados.

Parte 2: Encontrar el mayor subgrafo completamente conectado

Técnicas y estructuras de datos:
1. Grafo representado mediante un mapa de adyacencia:
   - Igual que en la Parte 1.
2. Búsqueda de subgrafos completamente conectados:
   - Se selecciona un nodo inicial.
   - Se construye un subgrafo agregando nodos conectados a todos los del subgrafo actual.
   - Se repite para todos los nodos del grafo.
3. Ordenación y generación de la contraseña:
   - El subgrafo más grande se ordena alfabéticamente con std::sort.
   - Se genera la contraseña concatenando nombres de nodos con comas.

Resolución:
1. Leer el grafo y construir el mapa de adyacencia.
2. Iterar sobre cada nodo como punto inicial para buscar subgrafos completamente conectados.
3. Comparar el tamaño del subgrafo con el mejor conocido.
4. Almacenar el mayor subgrafo encontrado.
5. Ordenar el subgrafo alfabéticamente y generar la contraseña.

Para la resolución de este día he adjuntado una representación visual de la red de conexiones del ejercicio.
Los nodos azules representan las computadoras, y las líneas muestran las conexiones entre ellas.
Los grupos densamente conectados corresponden a los subgrafos completamente conectados,
donde se encuentran las posibles LAN parties.

También he adjuntado una imagen de un meme con el que me he sentido identificado tras haber finalizado este trabajo.
