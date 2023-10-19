# Exercicio 04 - St. Petersburg Parties

St. Petersburg became after the end of the Iron Curtain in the early '90s, one of the main cities of the alternative scene worldwide. Groups of punks, hardcore bands and several other representatives of the alternative scene moved to the city, attracted by the large amount of young people. With the emergence of virtual communities, a few years later, it was noted the enormous potential of using these communities to combine meetings, parties, raves, etc..

In these celebrations of St. Petersburg is always very important that each participant has at least a certain number of friends on the social network. At the same time, we want to invite as many people as possible to St. Petersburg since the restriction on the number of friends is satisfied. This constraint says that, to be invited to the party, the person must have at least one number K of friends on the guest list.

Your task in this problem is, given the number of people in the community and to list their relationships, determine what should be called to the party that has the largest possible number of participants satisfying the constraint.

## Input
The input have many test cases and ends with the end of file (EOF). The first line of each test case contains three integers N (1 ≤ N ≤ 1000), M and K (O ≤ K ≤ N) representing respectively the number of people in the community, the number of friendships in this community and the minimum number of friends asked a person must have to be invited. Each person in the community is identified by numbers from 1 to N. Each of the next M lines of the test case contains a pair of people indicating that they are friends in the social network.

## Output
For each test case print a single line containing the list of people to invite separated by a blank space. The list should be sorted in ascending order. If anyone can be invited, print the number 0.

![Alt text](/st-petersburg-parties/image/output04.png)