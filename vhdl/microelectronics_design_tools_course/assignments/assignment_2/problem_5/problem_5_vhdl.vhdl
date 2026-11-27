library ieee;
use ieee.std_logic_1164.all;

entity dec4to16 is
    port 
    (
        w  : in  std_logic_vector(3 downto 0);
        En : in  std_logic;
        y  : out std_logic_vector(0 to 15)
    );
end dec4to16;

architecture structural of dec4to16 is
    component dec2to4
        port 
        (
            w  : in  std_logic_vector(1 downto 0);
            En : in  std_logic;
            y  : out std_logic_vector(0 to 3)
        );
    end component;

    signal m : std_logic_vector(0 to 3);
    begin
        -- First-stage decoder
        DEC_STAGE1: dec2to4 port map 
        (
            w  => w(3 downto 2),
            En => En,
            y  => m
        );

        -- Second-stage decoders
        DEC_0: dec2to4 port map 
        (
            w  => w(1 downto 0),
            En => m(0),
            y  => y(0 to 3)
        );

        DEC_1: dec2to4 port map 
        (
            w  => w(1 downto 0),
            En => m(1),
            y  => y(4 to 7)
        );

        DEC_2: dec2to4 port map 
        (
            w  => w(1 downto 0),
            En => m(2),
            y  => y(8 to 11)
        );

        DEC_3: dec2to4 port map 
        (
            w  => w(1 downto 0),
            En => m(3),
            y  => y(12 to 15)
        );
end structural;