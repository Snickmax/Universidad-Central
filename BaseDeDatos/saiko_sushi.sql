-- phpMyAdmin SQL Dump
-- version 5.2.1
-- https://www.phpmyadmin.net/
--
-- Servidor: 127.0.0.1
-- Tiempo de generación: 14-12-2023 a las 08:39:40
-- Versión del servidor: 10.4.32-MariaDB
-- Versión de PHP: 8.2.12

SET SQL_MODE = "NO_AUTO_VALUE_ON_ZERO";
START TRANSACTION;
SET time_zone = "+00:00";


/*!40101 SET @OLD_CHARACTER_SET_CLIENT=@@CHARACTER_SET_CLIENT */;
/*!40101 SET @OLD_CHARACTER_SET_RESULTS=@@CHARACTER_SET_RESULTS */;
/*!40101 SET @OLD_COLLATION_CONNECTION=@@COLLATION_CONNECTION */;
/*!40101 SET NAMES utf8mb4 */;

--
-- Base de datos: `saiko_sushi`
--

DELIMITER $$
--
-- Procedimientos
--
CREATE DEFINER=`root`@`localhost` PROCEDURE `ActualizarCarrito` (IN `p_Id_venta` INT, IN `p_Id_producto` INT, IN `p_cantidad` INT)   BEGIN
    DECLARE carrito_count INT;
    DECLARE actual_cantidad INT;

    -- Obtener la cantidad actual del carrito
    SELECT cantidad INTO actual_cantidad
    FROM carrito
    WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;

    -- Verificar si el elemento ya está en el carrito
    SELECT COUNT(*)
    INTO carrito_count
    FROM carrito
    WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;

    IF carrito_count > 0 THEN
        -- Si el elemento ya está en el carrito, actualizar la cantidad
        IF actual_cantidad - p_cantidad > 0 THEN
            UPDATE carrito
            SET cantidad = (actual_cantidad - p_cantidad)
            WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;
        ELSE
            -- Si la cantidad llega a cero o menos, eliminar la entrada del carrito
            DELETE FROM carrito
            WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;
        END IF;
    END IF;
END$$

CREATE DEFINER=`root`@`localhost` PROCEDURE `ActualizarCarrito2` (IN `p_Id_venta` INT, IN `p_Id_producto` INT, IN `p_cantidad` INT)   BEGIN
    DECLARE carrito_count INT;
    DECLARE actual_cantidad INT;

    -- Obtener la cantidad actual del carrito
    SELECT cantidad INTO actual_cantidad
    FROM carrito
    WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;

    -- Verificar si el elemento ya está en el carrito
    SELECT COUNT(*)
    INTO carrito_count
    FROM carrito
    WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;

    IF carrito_count > 0 THEN
        -- Si el elemento ya está en el carrito, actualizar la cantidad
        UPDATE carrito
        SET cantidad = (actual_cantidad + p_cantidad)
        WHERE Id_venta = p_Id_venta AND Id_producto = p_Id_producto;
    ELSE
        -- Si la cantidad llega a cero o menos, eliminar la entrada del carrito
        INSERT INTO carrito(Id_venta, Id_producto, nombre_producto, cantidad, precio) 
        VALUES (p_Id_venta, p_Id_producto, "", p_cantidad, 0);
    END IF;
END$$

--
-- Funciones
--
CREATE DEFINER=`root`@`localhost` FUNCTION `id` () RETURNS INT(10) UNSIGNED  BEGIN
  DECLARE ide INT UNSIGNED;
  SET ide = (
    SELECT Id_venta 
    FROM registro_venta
    WHERE Id_venta >= all(SELECT Id_venta 
    FROM registro_venta) );

  RETURN ide;
END$$

DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `carrito`
--

CREATE TABLE `carrito` (
  `Id_venta` int(11) NOT NULL,
  `Id_producto` int(11) NOT NULL,
  `nombre_producto` varchar(30) NOT NULL,
  `cantidad` int(11) NOT NULL,
  `precio` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Disparadores `carrito`
--
DELIMITER $$
CREATE TRIGGER `actualizar` BEFORE INSERT ON `carrito` FOR EACH ROW BEGIN
  DECLARE precio INT; 
  DECLARE nombre VARCHAR(30);  -- Ajusta la longitud según tus necesidades
  
  SET precio = (SELECT precio_producto FROM menu WHERE Id_producto = NEW.Id_producto);
  SET nombre = (SELECT nombre_producto FROM menu WHERE Id_producto = NEW.Id_producto);

  SET NEW.nombre_producto = nombre;
  SET NEW.precio = precio * NEW.cantidad;
END
$$
DELIMITER ;
DELIMITER $$
CREATE TRIGGER `actualizar2` BEFORE UPDATE ON `carrito` FOR EACH ROW BEGIN
  DECLARE precio INT; 
  DECLARE nombre VARCHAR(30);  -- Ajusta la longitud según tus necesidades
  
  SET precio = (SELECT precio_producto FROM menu WHERE Id_producto = NEW.Id_producto);
  SET nombre = (SELECT nombre_producto FROM menu WHERE Id_producto = NEW.Id_producto);

  SET NEW.nombre_producto = nombre;
  SET NEW.precio = precio * NEW.cantidad;
END
$$
DELIMITER ;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventario`
--

CREATE TABLE `inventario` (
  `Id_ingrediente` int(4) NOT NULL,
  `nombre_ingrediente` varchar(30) NOT NULL,
  `cantidad_ingrediente` int(3) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `inventario_menu`
--

CREATE TABLE `inventario_menu` (
  `Id_producto` int(4) NOT NULL,
  `Id_ingrediente` int(4) NOT NULL,
  `cantidad` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `menu`
--

CREATE TABLE `menu` (
  `Id_producto` int(4) NOT NULL,
  `nombre_producto` varchar(30) NOT NULL,
  `precio_producto` int(5) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

-- --------------------------------------------------------

--
-- Estructura de tabla para la tabla `registro_venta`
--

CREATE TABLE `registro_venta` (
  `Id_venta` int(11) NOT NULL,
  `Total` int(11) NOT NULL
) ENGINE=InnoDB DEFAULT CHARSET=utf8mb4 COLLATE=utf8mb4_general_ci;

--
-- Índices para tablas volcadas
--

--
-- Indices de la tabla `carrito`
--
ALTER TABLE `carrito`
  ADD PRIMARY KEY (`Id_venta`,`Id_producto`),
  ADD KEY `Id_producto` (`Id_producto`);

--
-- Indices de la tabla `inventario`
--
ALTER TABLE `inventario`
  ADD PRIMARY KEY (`Id_ingrediente`);

--
-- Indices de la tabla `inventario_menu`
--
ALTER TABLE `inventario_menu`
  ADD PRIMARY KEY (`Id_producto`,`Id_ingrediente`),
  ADD KEY `Id_ingrediente` (`Id_ingrediente`);

--
-- Indices de la tabla `menu`
--
ALTER TABLE `menu`
  ADD PRIMARY KEY (`Id_producto`);

--
-- Indices de la tabla `registro_venta`
--
ALTER TABLE `registro_venta`
  ADD PRIMARY KEY (`Id_venta`);

--
-- AUTO_INCREMENT de las tablas volcadas
--

--
-- AUTO_INCREMENT de la tabla `inventario`
--
ALTER TABLE `inventario`
  MODIFY `Id_ingrediente` int(4) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `menu`
--
ALTER TABLE `menu`
  MODIFY `Id_producto` int(4) NOT NULL AUTO_INCREMENT;

--
-- AUTO_INCREMENT de la tabla `registro_venta`
--
ALTER TABLE `registro_venta`
  MODIFY `Id_venta` int(11) NOT NULL AUTO_INCREMENT;

--
-- Restricciones para tablas volcadas
--

--
-- Filtros para la tabla `carrito`
--
ALTER TABLE `carrito`
  ADD CONSTRAINT `carrito_ibfk_1` FOREIGN KEY (`Id_producto`) REFERENCES `menu` (`Id_producto`),
  ADD CONSTRAINT `carrito_ibfk_2` FOREIGN KEY (`Id_venta`) REFERENCES `registro_venta` (`Id_venta`);

--
-- Filtros para la tabla `inventario_menu`
--
ALTER TABLE `inventario_menu`
  ADD CONSTRAINT `inventario_menu_ibfk_1` FOREIGN KEY (`Id_ingrediente`) REFERENCES `inventario` (`Id_ingrediente`) ON DELETE CASCADE ON UPDATE CASCADE,
  ADD CONSTRAINT `inventario_menu_ibfk_2` FOREIGN KEY (`Id_producto`) REFERENCES `menu` (`Id_producto`) ON DELETE CASCADE ON UPDATE CASCADE;
COMMIT;

/*!40101 SET CHARACTER_SET_CLIENT=@OLD_CHARACTER_SET_CLIENT */;
/*!40101 SET CHARACTER_SET_RESULTS=@OLD_CHARACTER_SET_RESULTS */;
/*!40101 SET COLLATION_CONNECTION=@OLD_COLLATION_CONNECTION */;
