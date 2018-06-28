![expression-roller][expression-roller]

# Expression-Roller
A simple infix expression evaluator that also parses dice rolls.



### Expression-Roller follows proper Orders of Operation by constructing a binary expression tree:

![expression-operation-orders][expression-operation-orders]


|          *2 * (1 + 1)*           |          *2 * 1 + 1*           |
| :-----------------------: | :-----------------------: |
| ![expression-tree1][expression-tree1] | ![expression-tree2][expression-tree2] |

----



### Valid operators:

​	**( X )** : Denotes X as a sub-expression.

​	**+X** : Denotes a positive X.

​	**X + Y** : Adds X to Y.

​	**-X** : Denotes a negative X.

​	**X - Y** : Subtracts X from Y.

​	**X * Y** : Multiplies X by Y.

​	**X / Y** : Divides X by Y.

​	**X % Y** : Divides X by Y and returns the remainder.

​	**X^Y** : Raises X to the Y power.

  ###### * Where X and Y ∈ ℚ.

![expression-rolls][expression-rolls]

​	**dA** : Rolls a single A sided die and returns the results. 

​	**AdB** : Rolls a B sided die A times and sums their results.

  ###### * Where A and B ∈ ℤ+.



----



### Expression-Roller can handle complex expressions: 

![expression-complex-rolls][expression-complex-rolls]

[expression-roller]: https://i.imgur.com/TB7H0rH.png
[expression-tree1]: https://i.imgur.com/r81ptse.png
[expression-tree2]: https://i.imgur.com/k0l9J9X.png
[expression-operation-orders]: https://i.imgur.com/KuWlfgP.png
[expression-rolls]: https://i.imgur.com/BlDXGZM.gif
[expression-complex-rolls]: https://i.imgur.com/alaUjaH.gif
