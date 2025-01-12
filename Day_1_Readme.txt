Día 1: Divide y Vencerás

Hemos decidido abordar este problema utilizando el método de divide y vencerás, ya que es una técnica eficiente para manejar problemas de ordenación y división de problemas más grandes en partes más pequeñas. En este caso, hemos utilizado la tecnica Merge Sort.

La idea principal es dividir el conjunto de datos en dos mitades de manera recursiva hasta que cada subgrupo contenga un solo elemento (o ninguno). Luego, fusionamos esos subgrupos de manera ordenada. Esto lo hace la función mergesort, que recursivamente divide el vector hasta llegar a las sublistas más pequeñas y las combina de manera ordenada mediante la función merge.

El uso de divide y vencerás en este caso resulta adecuado porque la estructura del problema requiere la ordenación de dos listas (left_side y right_side) para luego verificar la similitud entre ellas. Al dividir el problema en subproblemas más pequeños, la complejidad de ordenación se reduce, lo que lo hace más eficiente que otros métodos más simples, como la fuerza bruta.

Una vez que la lista de left_side se ordena, utilizamos un mapa hash (unordered_map) para contar cuántas veces aparece cada número en la lista de la izquierda y en la lista de la derecha. Esto permite analizar la similitud entre las dos listas, multiplicando las veces que aparece un número en cada lista. El uso de un mapa hash es imprescindible para realizar la comprobación y el conteo de manera eficiente.

El uso de divide y vencerás nos permite dividir el problema de ordenación en subproblemas más simples, lo que hace resolver el problema más ameno. La ordenación y el uso del mapa hash juntos permiten resolver el problema.

