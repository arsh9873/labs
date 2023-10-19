def func():
    # Read data from the file
    data = []
    with open("2_animal.txt", "r") as file:
        lines = file.readlines()
        attribute_names = lines[0].strip().split(',')[1:]
        for line in lines[1:]:  # Skip the header line
            line = line.strip().split(",")
            data.append(line)

    # print(attribute_names)

    # Convert data into a dictionary
    animal_data = []
    for entry in data:
        animal_dict = {"Animal": entry[0]}  # Initialize the dictionary with the animal's name
        
        # Add attributes to the dictionary
        for attr_name, attr_value in zip(attribute_names, entry[1:]):
            if attr_value != "NA":
                animal_dict[attr_name] = int(attr_value)
            else:
                animal_dict[attr_name] = 0
        animal_data.append(animal_dict)
    # print(animal_data)

    # Calculate Jaccard similarity for each pair
    similarities = []
    for i in range(len(animal_data)):
        for j in range(i + 1, len(animal_data)):
            common_attributes = sum(animal_data[i][attr] == animal_data[j][attr] for attr in attribute_names)
            unique_attributes = len(attribute_names)
            jaccard_similarity = common_attributes / unique_attributes
            similarities.append(((animal_data[i]['Animal'], animal_data[j]['Animal']), jaccard_similarity))

    similarities.sort(key=lambda x: x[1], reverse=True)

    print("Animals , Similarity size")
    for pair, similarity in similarities[:10]:
        print(f"({pair[0]}, {pair[1]}) , {similarity:.2f}")


if __name__ == '__main__':
    
    func()
