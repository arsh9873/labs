import math
data = """
age     income  student credit_rating buys_computer
<=30    high    no      fair          no
<=30    high    no      excellent     no
31-40   high    no      fair          yes
>40     medium  no      fair          yes
>40     low     yes     fair          yes
>40     low     yes     excellent     no
31-40   low     yes     excellent     yes
<=30    medium  no      fair          no
<=30    low     yes     fair          yes
>40     medium  yes     fair          yes
<=30    medium  yes     excellent     yes
31-40   medium  no      excellent     yes
31-40   high    yes     fair          yes
>40     medium  no      excellent     no
"""

data_lines = data.strip().split('\n')

attribute_names = data_lines[0].split()[1:-1] 

print(f"Attribute names: {attribute_names}")

def entropy(dataset):
    total_instances = len(dataset)
    if total_instances == 0:
        return 0

    positive_instances = sum(1 for row in dataset if row[-1] == 'yes')

    negative_instances = total_instances - positive_instances

    if positive_instances == 0 or negative_instances == 0:
        return 0

    p_positive = positive_instances / total_instances

    p_negative = negative_instances / total_instances

    return -p_positive * math.log2(p_positive) - p_negative * math.log2(p_negative)


def information_gain(dataset, attribute_index):
    total_entropy = entropy(dataset)

    unique_values = set(row[attribute_index] for row in dataset)

    weighted_entropy = 0

    for value in unique_values:
        subset = [row for row in dataset if row[attribute_index] == value]
        subset_entropy = entropy(subset)
        weight = len(subset) / len(dataset)
        weighted_entropy += weight * subset_entropy

    return total_entropy - weighted_entropy


data_lines = data_lines[1:]
dataset = [line.split() for line in data_lines]

for i, attribute_name in enumerate(["age"] + attribute_names):
    ig = information_gain(dataset, i)
    print(f"Information Gain for {attribute_name}: {ig:.4f}")
