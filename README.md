# Report
| UFID | 45705087      |
| Name | Alexander Dao |

## Variables
k = cache capacity
m = number of requests
max_int = range of integer id from 0 to max_int
r = sequence of requests

## Question 1
|        | k  | m      | max_int | FIFO  | %  | LRU   | %  | OTFF  | %  |
| test 1 | 5  | 50     | 10      | 30    | 60 | 29    | 58 | 18    | 36 |
| test 2 | 50 | 500    | 100     | 282   | 56 | 279   | 56 | 164   | 33 |
| test 3 | 50 | 500000 | 100     | 98566 | 20 | 98013 | 20 | 21839 | 4  |

1) OPTFF has the lowest miss chance

2) FIFO roughly equals LRU

## Question 2
Yes, there exists a sequence where OTFF is better than LRU. It would be k = 3, r = 1 2 3 4 1 2 with the following miss chances: LRU: 6/6 miss, OTFF: 4/6 miss.

LRU is generally worse than OTFF since LRU looks backwards to determine which cache to replace and OTFF looks forwards. Cache misses only happen due to inserting future data that is not in the current cache so looking forward gives more relevant data to avoid cache misses.

## Question 3
Let's say there is another alogrithmn, A, that is optimal and is not optff. For time t = 0, both are empty and the equivalence is trivial. For sequence of r up to time t, the two algorithmn agree, and at r of t+1 they disagree and the optimal ejects e1 while optff ejects e2. Thus, at t + 1, optimal holds onto e2, and optoff holds onto e1. After t + 1, every other k - 1 slots are still the same thus optimal and optoff can be equivalent for any value other than e1 or e2 up until e1 is requested.

For values e1 and e2, if e1 and e2 are different then e1 will always be requested before e2. Thus optimal will always get a cache miss first, and thus will always be worse than optff until e2 is requested.

Thus optff cannot be worse than optimal and thus optff is optimal.

# Compilation

## Nix Method (Tested and Reccomended)

Dependencies: nix (nix-stable 25.11)

The main compile code is

``` bash
nix-shell --pure --run ./test.sh
```

## Manual (Untested)

Direnv reads the .envrc to generate the directory level configurations, .direnv/ and .cache/, for any lsp servers within nix. Running ./test.sh is required to for bear to generate a compile_commands.json environment file and the binaries in binary/.

Read through shell.nix for manual dependencies, test.sh for how to compile using those dependencies including any compilation flags and how to pipe in the inputs and outputs for the two cpp programs.

## Test Cases
Are found in the tests/ folder where each sub folder is an independent test with an input.txt. The tests cases are ran by ./test.sh, thus by reading ./test.sh you will understand how to reproduce the output.

The input.txt has 3 integers:
- k which is the cache capacity
- m which is the number of id
- max_int which is the max size of the int

The test-case.txt matches the test case format provided in the assignment, you can inject any manual professor provided test cases in the same manner as how test.sh calls for test-case.txt.

The output of main will be to std::out so feel free to use bash > to redirect it into a file as needed.
