#How to create an arrayfire package

RcppArrayFire::RcppArrayFire.package.skeleton(name="arrayfire",
                                              environment=.GlobalEnv,
                                              path="/Users/sfurla/Box Sync/PI_FurlanS/computation/Rproj",
                                              force=FALSE,
                                              code_files=character(),
                                              example_code=TRUE)

#Create repo on github - no readme

#Run this
cd arrayfire/
git init
git add .
git commit -m "firstcommit"
git remote add origin https://github.com/scfurl/arrayfire.git
git remote -v
git push -u origin master

devtools::document()
roxygen2::roxygenise()
