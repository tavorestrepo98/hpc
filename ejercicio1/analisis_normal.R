datos_10 <- c(0.000512, 0.000478, 0.000474, 0.000475, 0.000485, 0.000475, 0.000477, 0.000479, 0.000472, 0.000485)
mean(datos_10)
sd(datos_10)

datos_50 <- c(0.062175, 0.061926, 0.0619,0.061884, 0.062402, 0.06171, 0.062763,0.062133, 0.062922, 0.062372)
mean(datos_50)
sd(datos_50)

datos_100 <- c(0.505082, 0.50003, 0.503369, 0.508729, 0.501997, 0.49943, 0.504751, 0.502334, 0.503505, 0.505015)
mean(datos_100)
sd(datos_100)

datos_200 <- c(5.52435, 5.56256, 5.50136, 5.52048, 5.5399, 5.59625, 5.5352, 5.58384, 5.51444, 5.56929)
mean(datos_200)
sd(datos_200)

datos_300 <- c(22.1025, 22.0006, 22.2934, 22.2829, 22.632, 22.0954, 22.0335, 22.6651, 22.5863, 22.4821)
mean(datos_300)
sd(datos_300)

datos_400 <- c(64.5084, 65.1833, 64.3154, 64.7881, 64.3391, 64.7319, 64.9618, 64.7168, 64.6901, 65.0662)
mean(datos_400)
sd(datos_400)

datos_500 <- c(145.721, 146.065, 146.353, 145.344, 145.701, 145.42, 145.614, 145.447, 145.762, 145.696)
length(datos_500)
mean(datos_500)
sd(datos_500)

tiempo_s <- c(mean(datos_10), mean(datos_50), mean(datos_100), mean(datos_200), mean(datos_300), mean(datos_400), mean(datos_500))
tamaño_s<- c(10, 50, 100, 200, 300, 400, 500)

mult_mat <- data.frame(tamaño_s, tiempo_s)
head(mult_mat, 7)
tiempo_s


dev.off()

plot(datos_matrices, tiempos_medios, ylab = "Tiempo (s)", xlab = "Tamaño matriz", main = "Programa Sin Hilos", type = "o")
