""""""
TYPE_CPP2PY = {
    "char": "char",
    "int": "int",
    "double": "double",
    "short": "int"
}


class DataTypeGenerator:
    """DataType生成器"""

    def __init__(self, filename: str, prefix: str):
        """Constructor"""
        self.filename = filename
        self.prefix = prefix
        self.enums = {}
        self.enums_map = {}
        self.last = ""

    def run(self):
        """主函数"""
        self.f_cpp = open(self.filename, "r")
        self.f_define = open(f"{self.prefix}_constant.py", "w")
        self.f_typedef = open(f"{self.prefix}_typedef.py", "w")

        for line in self.f_cpp:
            self.process_line(line)

        self.write()

        self.f_cpp.close()
        self.f_define.close()
        self.f_typedef.close()

        print("DataType生成完毕")

    def process_line(self, line: str):
        """处理每行"""
        line = line.replace("\n", "")
        line = line.split(";")[0]
        line = line.replace("\t", " ")

        if "const" in line:
            self.process_define(line)
        elif "typedef" in line and "__int64" not in line:
            self.process_typedef(line)
        elif "enum" in line:
            pass
            # self.process_enum(line)
        elif line.replace(" ", "") and "{" not in line and "}" not in line and "///" not in line and "#" not in line and "__" not in line:
            line = line.replace(" ", "")
            if "=" in line:
                new_line = line.replace("=0,", "") + " = 1\n"
            elif "," in line:
                new_line = line.replace(",", "") + " = 1\n"
            else:
                new_line = line.replace(",", "") + " = 2\n"
            self.f_define.write(new_line)

    def process_define(self, line: str):
        """处理常量定义"""
        words = line.split(" ")
        words = [word for word in words if word]
        if len(words) < 3:
            return

        if "=" in words:
            name = words[2]
            value = words[-1]

        new_line = f"{name} = {value}\n"
        self.f_define.write(new_line)

    def process_enum(self, line: str):
        """处理枚举值定义"""
        words = line.split(" ")
        words = [word for word in words if word]

        name = words[1]

        if "{" in name:
            name = name.replace("{", "")
        self.last = name
        self.enums[name] = "enum"

    def process_typedef(self, line: str):
        """处理类型定义"""
        words = line.split(" ")
        words = [word for word in words if word != ""]

        name = words[-1]
        if len(words) > 3:
            typedef = " ".join(words[1:-2])
        else:
            typedef = TYPE_CPP2PY[words[1]]

        if typedef == "char":
            if "[" in name:
                typedef = "string"
                name = name[:name.index("[")]

        new_line = f"{name} = \"{typedef}\"\n"
        # print(line, typedef)
        self.f_typedef.write(new_line)

    def write(self):
        for k, v in self.enums.items():
            if "{" in k:
                k = k.replace("{", "")
            new_line = f"{k} = \"{v}\"\n"
            self.f_typedef.write(new_line)


if __name__ == "__main__":
    # generator = DataTypeGenerator("../include/tora/TORATstpXMdApiDataType.h", "toramd")
    # generator.run()

    # generator = DataTypeGenerator("../include/tora/TORATstpSPUserApiDataType.h", "toraoption")
    # generator.run()

    generator = DataTypeGenerator("../include/tora/TORATstpUserApiDataType.h", "torastock")
    generator.run()
