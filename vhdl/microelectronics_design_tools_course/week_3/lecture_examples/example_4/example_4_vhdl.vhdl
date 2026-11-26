library ieee;
use ieee.std_logic_1164.all;

entity dec21 is
    port
    (
        en: in std_logic;
        w: in std_logic_vector;
        y: out std_logic_vector(3 downto 0)
    );
end entity dec21;

architecture rtl of dec21 is
    begin
        y < "0000" when en = '0' else
            "0001" when w = "00" else
            "0010" when w = "01" else
            "0100" when w = "10" else
            "1000";
    end architecture rtl;

