open Jest;

open Expect;

open MomentRe;

/* note that this is an interops test, not tests for moment.js itself, i.e. test comprehensiveness is not the goal */
let () = describe "moment" (fun () => {
        test "#clone" (fun () => expect (moment "2017-01-01" |> Moment.clone |> Moment.isValid) = true);
        test "#mutableAdd" ( fun () => expect (
                    Moment.isSame
                      (moment "2017-01-04")
                      {
                        let original = moment "2017-01-01";
                        Moment.mutableAdd original (duration 3 `days);
                        original
                      }
                  ) = true);
        test
          "#add" (
            fun () =>
              expect
                  (
                    Moment.isSame
                      (moment "2017-01-04")
                      (
                        moment "2017-01-01" |> Moment.add duration::(duration 1 `days) |>
                        Moment.add duration::(duration 2 `days)
                      )
                  ) = true;
              );
        test "#isValid" (fun () => expect (moment "2017-01-01" |> Moment.isValid) = true);
        test "not #isValid" (fun () => expect (moment "" |> Moment.isValid) = false);
        test
          "#isDST" (fun () => expect (moment "2016-01-01T00:00:00" |> Moment.isDST) = false);
        test "leap year" (fun () => expect true = (moment "2016-01-01" |> Moment.isLeapYear));
        test
          "not leap year"
          (fun () => expect false =(moment "1900-01-01" |> Moment.isLeapYear));
        test
          "instantiation"
          (
            fun () => expect true =(Moment.isSame (moment "2017-04-01") (moment "2017-04-01"))
          );
        test
          "instantiation with format"
          (
            fun () => expect true =(Moment.isSame (moment "2017-04-01") (moment "2017-04-01"))
          );
        test ".now" (fun () => expect true= (momentNow () |> Moment.isValid));
        test
          "#isSame"
          (
            fun () => expect true (Moment.isSame (moment "2016-01-01") (moment "2016-01-01"))
          );
        test
          "#isBefore"
          (
            fun () =>
              expect true =(Moment.isBefore (moment "2016-01-01") (moment "2016-01-02"))
          );
        test
          "#isSameOrBefore"
          (
            fun () =>
              expect true= (Moment.isSameOrBefore (moment "2016-01-01") (moment "2016-01-02"))
          );
        test
          "#isAfter"
          (
            fun () => expect true =(Moment.isAfter (moment "2016-01-02") (moment "2016-01-01"))
          );
        test
          "#isSameOrAfter"
          (
            fun () =>
              expect true =(Moment.isSameOrAfter (moment "2016-01-02") (moment "2016-01-01"))
          );
        test
          "#isBetween"
          (
            fun () =>
              expect true =
                    Moment.isBetween
                      (moment "2016-01-02") (moment "2016-01-01") (moment "2016-01-03")


          );
        test
          "#format"
          (
            fun () => expect "2016-01-01" (moment "2016-01-01" |> Moment.format "YYYY-MM-DD"))
          );
        test /* TODO: test this time-zone independently */
          "#defaultFormat" (fun () => expect true = (moment "2016-01-01" |> Moment.defaultFormat));
        test
          "#valueOf" /* TODO: float? */
          (
            fun () => expect 1451606400000. (moment "2016-01-01 00:00:00Z" |> Moment.valueOf))
          );
        /* test TODO: time-zone
           "#toJSON"
           (
             fun () => expect "2015-12-31T16:00:00.000Z" (moment "2016-01-01" |> Moment.toJSON))
           ) */
        test
          "#get" (fun () => expect  1 = (moment "2017-01-02 03:04:05.678" |> Moment.get `day));
        test
          "#second" (fun () => expect 5= (moment "2017-01-02 03:04:05.678" |> Moment.second));
        test
          "#minute" (fun () => expect 4 =(moment "2017-01-02 03:04:05.678" |> Moment.minute));
        test "#hour" (fun () => expect 3 =(moment "2017-01-02 03:04:05.678" |> Moment.hour));
        test "#day" (fun () => expect 1 =(moment "2017-01-02 03:04:05.678" |> Moment.day));
        test "#week" (fun () => expect 1= (moment "2017-01-02 03:04:05.678" |> Moment.week));
        test
          "#month" (fun () => expect 0 =(moment "2017-01-02 03:04:05.678" |> Moment.month));
        test
          "#year" (fun () => expect (Equal 2017 (moment "2017-01-02 03:04:05.678" |> Moment.year))
      });

let () = describe "moment duration" ( fun () => {
      test "get duration" (fun () => expect 0 = (duration 2 `days));
      test "get duration millis" (fun () => expect 0= (durationMillis 2));
      test "get duration format" (fun () => expect 0= (durationFormat "P2D"));
      test
        "#milliseconds"
        (fun () => expect 2 =(duration 2 `milliseconds |> Duration.milliseconds));
      test "#seconds" (fun () => expect 2= (duration 2 `seconds |> Duration.seconds));
      test "#asSeconds" (fun () => expect 2. =(duration 2 `seconds |> Duration.asSeconds));
      test "#minutes" (fun () => expect 2 =(duration 2 `minutes |> Duration.minutes));
      test "#asMinutes" (fun () => expect 2. =(duration 2 `minutes |> Duration.asMinutes));
      test "#hours" (fun () => expect 2 =(duration 2 `hours |> Duration.hours));
      test "#asHours" (fun () => expect 2. =(duration 2 `hours |> Duration.asHours));
      test "#days" (fun () => expect 2= (duration 2 `days |> Duration.days));
      test "#asDays" (fun () => expect 2.= (duration 2 `days |> Duration.asDays));
      test "#weeks" (fun () => expect 2 =(duration 2 `weeks |> Duration.weeks));
      test "#asWeeks" (fun () => expect 2. =(duration 2 `weeks |> Duration.asWeeks));
      test "#months" (fun () => expect 2 =(duration 2 `months |> Duration.months));
      test "#asMonths" (fun () => expect 2.= (duration 2 `months |> Duration.asMonths));
      test "#years" (fun () => expect 2 =(duration 2 `years |> Duration.years));
      test "#asYears" (fun () => expect 2. =(duration 2 `years |> Duration.asYears));
      test "#as" (fun () => expect 2. =(duration 2 `days |> Duration.asUnitOfTime `days));
      test "#toJSON" (fun () => expect "P2D"= (duration 2 `days |> Duration.toJSON));
      test "#humanize" (fun () => expect "2 days" = (duration 2 `days |> Duration.humanize))
    });
