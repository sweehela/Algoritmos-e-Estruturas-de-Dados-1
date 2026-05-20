Nome: Gabriela de Carvalho Bruno
Exercicio: 503. Given a circular integer array nums (i.e., the next element of nums[nums.length - 1] is nums[0]), return the next greater number for every element in nums.
The next greater number of a number x is the first greater number to its traversing-order next in the array, which means you could search circularly to find its next greater number. If it doesn't exist, return -1 for this number.

Caso 1: Input: nums = [1,2,1]
        Output: [2,-1,2]

Caso 2: Input: nums = [1,2,3,4,3]
        Output: [2,3,4,-1,4]

Caso 3: Input: mat nums = [8,7,4,6]
        Output: [-1,8,6,8]