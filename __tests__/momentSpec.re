open MomentRe;

let () =
  Jest.describe "moment" (fun () => {

    Jest.test "instantiation" (fun () => {
      Jest.Just (Jest.Truthy (
        Moment.isSame
          (moment "2017-04-01")
          (moment "2017-04-01")
        ));
    });

    Jest.test "instantiation with format" (fun () => {
      Jest.Just (Jest.Truthy (
        Moment.isSame
          (moment format::"YYYY-MM-DD" "2017-04-01")
          (moment format::"YYYY-MM-DD" "2017-04-01")
        ));
    });

    Jest.test "now" (fun () => {
      Jest.Just (Jest.Truthy (
        Moment.isSameOrBefore
          (moment_now ())
          (moment_now ())
        ));
    });

  });
