-- part b
library ieee;
use ieee.std_logic_1164.all;

entity SISO_shift_reg is
    generic (N : integer := 4);
    port 
    (
        SI, EN, CK : in  std_logic;
        SO         : out std_logic
    );
end SISO_shift_reg;

architecture structural of SISO_shift_reg is
    component DFF
        port 
        (
            D, EN, CK : in  std_logic;
            Q         : out std_logic
        );
    end component;

    signal q0, q1, q2 : std_logic;
    begin
        DFF_0: DFF port map 
        (
            D  => SI,

            EN => EN,
            CK => CK,

            Q  => q0
        );

        DFF_1: DFF port map 
        (
            D  => q0,

            EN => EN,
            CK => CK,

            Q  => q1
        );

        DFF_2: DFF port map 
        (
            D  => q1,

            EN => EN,
            CK => CK,

            Q  => q2
        );

        DFF_3: DFF port map 
        (
            D  => q2,

            EN => EN,
            CK => CK,
            
            Q  => SO
        );
end structural;