library ieee;
use ieee.std_logic_1164.all;
use ieee.numeric_std.all;

entity alu_ns is
    generic (WIDTH: positive := 16);
    port
    (
        input_1, input_2: in std_logic_vector(WIDTH-1 downto 0);
        sel: in std_logic_vector(3 downto 0);
        output_1: out std_logic_vector(WIDTH-1] downto 0);
        overflow: out std_logic
    );
end entity alu_ns;