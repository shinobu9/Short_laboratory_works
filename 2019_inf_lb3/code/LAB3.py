class HouseScheme:
    def __init__(self, rooms_count, indoor_area, bathroom_type):
        if (type(rooms_count) == int) and (rooms_count >= 0) and \
           (type(indoor_area) == int) and (indoor_area >= 0) and \
           (type(bathroom_type) == bool):
            self.rooms_count = rooms_count
            self.indoor_area = indoor_area
            self.bathroom_type = bathroom_type
        else:
            raise ValueError("Invalid value")

class CountryHouse(HouseScheme):
    def __init__(self, rooms_count, indoor_area, bathroom_type, floors_count, land_area):
        super().__init__(rooms_count, indoor_area, bathroom_type)
        if (type(floors_count) == int) and \
           (floors_count > 0) and \
           (type(land_area) == int) and \
           (land_area >= indoor_area):
            self.floors_count = floors_count
            self.land_area = land_area
        else:
            raise ValueError("Invalid value")
 
    def __str__(self):
        return "Country House: Количество жилых комнат " + str(self.rooms_count) + \
               ", Жилая площадь " + str(self.indoor_area) + \
               ", Совмещенный санузел " + str(self.bathroom_type) + \
               ", Количество этажей " + str(self.floors_count) + \
               ", Площадь участка " + str(self.land_area) + "."
    
    def __eq__(self, other):
    	return (self.indoor_area == other.indoor_area) and \
               (self.land_area == other.land_area) and \
               (abs(self.floors_count - other.floors_count) <= 1)

class Apartment(HouseScheme):
    def __init__(self, rooms_count, indoor_area, bathroom_type, floor, windows_dir):
        super().__init__(rooms_count, indoor_area, bathroom_type)
        if (type(floor) == int) and (0 < floor < 16) and (windows_dir in ['N','S','W','E']):
            self.floor = floor
            self.windows_dir = windows_dir
        else:
            raise ValueError("Invalid value")

    def __str__(self):
        return "Apartment: Количество жилых комнат " + str(self.rooms_count) + \
               ", Жилая площадь " + str(self.indoor_area) + \
               ", Совмещенный санузел " + str(self.bathroom_type) + \
               ", Этаж " + str(self.floor) + \
               ", Окна выходят на " + str(self.windows_dir) + "."

class CountryHouseList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name
    
    def append(self, p_object):
        if isinstance(p_object, CountryHouse):
            super().append(p_object)
        else:
            raise TypeError(f"Invalid type {type(p_object)}")

    def total_square(self):
        square_sum = 0
        for house in self:
            square_sum += house.indoor_area
        return square_sum

class ApartmentList(list):
    def __init__(self, name):
        super().__init__()
        self.name = name

    def extend(self, iterable):
        for elem in iterable:
            if isinstance(elem, Apartment):
                super().append(elem)

    def floor_view(self, floors, directions):
        for flat in list(filter(lambda x: (x.floor >= floors[0]) and \
                                          (x.floor <= floors[1]) and \
                                          (x.windows_dir in directions), self)):
            print(f"{flat.windows_dir}: {flat.floor}")