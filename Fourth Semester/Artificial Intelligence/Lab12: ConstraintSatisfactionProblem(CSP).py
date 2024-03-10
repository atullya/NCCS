from __future__ import print_function
from simpleai.search import CspProblem, backtrack, min_conflicts

variables = ('WA', 'NT', 'SA', 'Q', 'NSW', 'V', 'T')

domains = {v: ['red', 'green', 'blue'] for v in variables}

def const_different(variables, values):
    return values[0] != values[1]

constraints = [
    (('WA', 'NT'), const_different),
    (('WA', 'SA'), const_different),
    (('SA', 'NT'), const_different),
    (('SA', 'Q'), const_different),
    (('NT', 'Q'), const_different),
    (('SA', 'NSW'), const_different),
    (('Q', 'NSW'), const_different),
    (('SA', 'V'), const_different),
    (('NSW', 'V'), const_different),
]

my_problem = CspProblem(variables, domains, constraints)

print(backtrack(my_problem))
print(backtrack(my_problem, variable_heuristic='most_constrained_variable'))
print(backtrack(my_problem, variable_heuristic='highest_degree_variable'))
print(backtrack(my_problem, value_heuristic='least_constraining_value'))
print(backtrack(my_problem, variable_heuristic='most_constrained_variable', value_heuristic='least_constraining_value'))
print(backtrack(my_problem, variable_heuristic='highest_degree_variable', value_heuristic='least_constraining_value'))
print(min_conflicts(my_problem))
 
