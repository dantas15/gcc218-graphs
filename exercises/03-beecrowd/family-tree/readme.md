## Exercicio 02 - Family Tree

Amindo needs your help. He is working on a project based in some old documents (scattered and not organized, of course) in which he wants to identify and draw genealogic trees of different families.

See the image below: Pedro is Maria's Husband and they have three children: Josias, Mangojata and Samuel. Obviously Maria is mother of Mangojata and Samuel. Josias is Mangojata's brother and Mangojata is the mother of Ivane. Samuel is his uncle. There is also another different family with 2 persons, in which Paulo is Marcos's son.

![Alt text](/family-tree/images/example02.png)

Your help is very important in this work in order to identify how many different families exist based on existent documentation and relations provided by Armindo. In the image you can see 2 differents families: Pedro Family's and Marcos Family's.

## Input

The input consists of a single test case that contains many rows (can have up to a thousand rows). The first line contains two integers M (1 < M ≤ 300) and N (1 < N ≤ 200) that indicates respectively the amount of different people and the existent relationships between them. Each of the next N relationships (listed below), contains three words: a person's name followed by a relation and another name, all separated with space (there is no space after the last name).

Note: there will never be a name representing two different people. If there are 2 Pedros, for example, they will be identified by Pedro_1 and Pedro_2 and so on,

## Output
The output consist of a single integer representing the number of different families encountered, based on the documents provided by Armindo.

![Alt text](/family-tree/images/output02.png)