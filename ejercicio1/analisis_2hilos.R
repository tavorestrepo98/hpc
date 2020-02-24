datos_10hilos <- c(0.0004095, 0.0003265, 0.0003175, 0.0003135, 0.0003165, 0.0003145, 0.000317, 0.0003245, 0.0003125, 0.000305)
mean(datos_10hilos)
sd(datos_10hilos)

datos_50hilos <- c(0.03211, 0.031465, 0.0315705, 0.0314145, 0.0314405, 0.0317595, 0.031431, 0.0317675, 0.032059, 0.0319675)
mean(datos_50hilos)
sd(datos_50hilos)

datos_100hilos <- c(0.263925, 0.263329, 0.262079, 0.266417, 0.260526, 0.262829, 0.262531, 0.262699, 0.263042, 0.26412)


datos_200hilos <- c(2.39391, 2.41359, 2.41655, 2.4512, 2.39725, 2.39283, 2.40167, 2.41617, 2.40466, 2.396)

datos_300hilos <- c(10.0564, 10.0321, 10.0338, 10.1001, 10.0875, 10.0664, 10.0979, 10.0697, 10.0994, 10.0465)
mean(datos_300hilos)

datos_400hilos <- c(26.2595, 26.1735, 26.2713, 26.2415, 26.2202, 26.3778, 26.3419, 26.1674, 26.1354, 26.096)

datos_500hilos <- c(56.7133, 56.063, 56.0375, 56.2211, 56.1372, 56.1978, 56.1465, 56.1755, 56.2399, 56.1686)

tiempos_medios_hilos <- c(mean(datos_10hilos), mean(datos_50hilos), mean(datos_100hilos), mean(datos_200hilos), mean(datos_300hilos), mean(datos_400hilos), mean(datos_500hilos))
datos_matrices_hilos <- c(10, 50, 100, 200, 300, 400, 500)


dev.off()

plot(datos_matrices_hilos, tiempos_medios_hilos, ylab = "Tiempo (s)", xlab = "Tamaño matriz", main = "programa con 2 hilos", type = "o", col = "red")



